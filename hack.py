from glob import iglob
from os.path import (
    basename,
    isfile,
    join,
    splitext,
)
from subprocess import run, check_output

# EDIT ME
origin = '/home/neomi/noi-2023/training/week-5/my'
tohack = '/home/neomi/noi-2023/training/week-5/hackables'

excluded = {'lunar_bloom'}

bruteforce_ext = '.naive'  # e.g. 'solution.naive.cpp'

constraints_separator = ' '

timeout_tolerance = 2
# -------

def compile(basename, *, source, destination):
    if basename not in source:
        run(['g++', join(source, f'{basename}.cpp'), '-o', join(destination, f'{basename}.exe')])
    else:
        run(['g++', source, '-o', join(destination, f'{basename}.exe')])

def check(file):
    if not isfile(file):
        return False
    
    return all(x not in file for x in excluded)

def good(this, that, *, is_brute, id):
    input = join(exes, 'input.txt')
    ts_output = join(outs, 'output.this.txt')
    tt_output = join(outs, 'output.that.txt')
    for seed in range(1, amount + 1):
        with open(input, 'w') as inp:
            run([join(exes, 'generate.exe'), str(seed), *(brute if is_brute else large)], stdout=inp)
        try:
            with open(input, 'r') as inp:
                with open(ts_output, 'w') as output:
                    run([this], stdin=inp, stdout=output, timeout=timeout)
        except:
            return False
        try:
            with open(input, 'r') as inp:
                with open(tt_output, 'w') as output:
                    run([that], stdin=inp, stdout=output, timeout=timeout)
            
            check_output(['diff', ts_output, tt_output])
        except Exception as e:
            print(id, e)
            with open(join(dubs if str(e).find('timed out') != -1 else subs, f'{id}.py'), 'w') as submission:
                print(f'# This submission hacks {id}\n', file=submission)
                with open(input, 'r') as inp:
                    for line in inp.readlines():
                        print(f'print("{line.strip()}")', file=submission)
            return False
    return True
            

if __name__ == '__main__':
    timeout = float(input('Timeout: ')) * timeout_tolerance
    
    problem = input('Problem name: ')

    amount = int(input('Amount of tests per run: '))
    
    brute = input('Constraints for brute testing: ').split(constraints_separator)
    large = input('Constraints for large testing: ').split(constraints_separator)

    origin = join(origin, problem)
    tohack = join(tohack, problem)

    subs = join(tohack, problem)
    exes = join(tohack, 'executables')
    outs = join(tohack, 'outputs')
    dubs = join(subs, 'dubious')

    for directory in (
        subs,
        exes,
        outs,
        dubs,
    ):
        run(['mkdir', directory])

    for file in (
        'solution',
        f'solution{bruteforce_ext}',
        'generate'
    ):
        compile(file, source=origin, destination=exes)

    for file in filter(check, iglob(join(tohack, '**', '*.cpp'), recursive=True)):
        submission_id, _ = splitext(basename(file))
        compile(submission_id, source=file, destination=exes)
        for this, that, is_brute, id in (
            (join(exes, f'solution{bruteforce_ext}.exe'), join(exes, f'{submission_id}.exe'), True, submission_id),
            (join(exes, f'solution{bruteforce_ext}.exe'), join(exes, 'solution.exe'), True, 'my_solution'),
            (join(exes, 'solution.exe'), join(exes, f'{submission_id}.exe'), False, submission_id),
        ):
            if not good(this, that, is_brute=is_brute, id=id):
                break

    if list(filter(check, iglob(join(subs, '*.py'), recursive=True))) or list(filter(check, iglob(join(dubs, '*.py'), recursive=True))):
        run(['tar', '-czf', f'{subs.removesuffix("/")}.tar.gz', '-C', subs, '.'])