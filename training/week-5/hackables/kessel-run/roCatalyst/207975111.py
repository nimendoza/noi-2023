n, h = map(int,input().split())
memo = {0:0,1:1}
c = [int(x) for x in input().split()]
list.sort(c)

def minimize(hi):
    if hi in memo:
        return memo[hi]
    else:
        m = 1e8
        for ci in c:
            if hi >= ci:
                m = min(m,1+minimize(hi-ci))
            else:
                break
        memo[hi] = m
        return m
    
ans = 0
for i in range(1,h+1):
    ans = minimize(i)
print(ans)