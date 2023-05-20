from itertools import combinations

def solve(candies):
  for pair in combinations(candies, 2):
    if sum(pair) & 1:
      return 'Candies for everyone!'
  return 'No candy for Mom :('

def main():
  candies = list(map(lambda _: int(input()), range(7)))
  print(solve(candies))

if __name__ == '__main__':
  main()