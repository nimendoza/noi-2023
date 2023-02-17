amogus = [['1000', '0011', '0000', '1010'], ['0111', '1100', '1111', '0101']]

def wrap(n, s, c):
    return list(s[i:i + c] for i in range(0, n, c))

def count(grid):
    count = 0
    for y in range(0, len(grid) - 3):
        for x in range(len(grid[y + 3])):
            for imposter in amogus:
                for r in range(len(imposter)):
                    if not grid[y + r][x:].startswith(imposter[r]):
                        break
                else:
                    count += 1
    return count

def solve(n, s, c):
    grid = wrap(n, s, c)
    return count(grid)

def main():
    n = int(input())
    s = input()
    print(max([0] + list(solve(n, s, c) for c in range(4, n))))

if __name__ == '__main__':
    main()