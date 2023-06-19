p,v,memo=[1,0,0],[0,0,0],{}
q,p[1],p[2],v[0],v[1],v[2]=map(int,input().split())
def uks(k):
    if memo.get(k):return memo[k]
    maxval=0
    for i in range(3):
        if p[i]<=k:
            maxval=max(maxval,v[i]+uks(k-p[i]))
    memo[k]=maxval;return memo[k]
for _ in range(q):
    print(uks(int(input())))
    memo={}