import math
t = int(input())

for _ in range(t):
    n, c = map(int,input().split())
    l = [int(x) for x in input().split()]
    list.sort(l,reverse=True)

    for i in range(1,sum(l)+1):
        cuts = 0
        for li in l:
            
            cuts += math.ceil(li/i) - 1
            if cuts > c:
                break

        if cuts <= c:
            print(i)
            break