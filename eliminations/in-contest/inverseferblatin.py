vowels = set('aeiou')

def _1(word: str):
  if not word[1:].startswith('erb'):
    return
  if set(word[0] + word[4:]).intersection(vowels):
    return
  return word[0] + word[4:]

def _2(word: str):
  if word[0] not in vowels:
    return
  if not word.endswith('ferbe'):
    return
  return word[:-5]

def move_suffix(word: str):
  for i in range(len(word))[::-1]:
    if word[i] in vowels:
      break
  return word[i + 1:] + word[:i + 1]

def _3(word: str):
  if word[0] not in vowels:
    return
  if not word.endswith('werb'):
    return
  if word[-5] in vowels:
    return
  if word[-6] not in vowels:
    return True
  return move_suffix(word[:-4])

def reverse(transformed: str):
  if len(transformed) >= 4:
    yield _1(transformed)
  if len(transformed) >= 6:
    yield _2(transformed)
    yield _3(transformed)

def solve(word: str):
  words = set(reverse(word)).difference([None])
  if len(words) > 1 or True in words:
    return 'SECRET'
  if not words:
    return 'NONE'
  return words.pop()

def main():
  for _ in range(int(input())):
    print(solve(input()))

if __name__ == '__main__':
  main()