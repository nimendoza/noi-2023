def solve(times):
  if len(times) == 1:
    return 'has', 1, 'incident'
  return 'have', len(times), 'incidents'

def main():
  times = set(input().split(', '))
  print('There {} been {} {} of cheating in the past.'.format(*solve(times)))

if __name__ == '__main__':
  main()