t=int(input())
for _ in range(t):
    n=int(input());g=[]
    for _ in range(n):
        a,b=map(int,input().split())
        g.append((a,b))
    def elim_int(arr,ele):
        return [x for x in arr if x[1]<ele[0] or x[0]>ele[1]]
    def rec(arr):
        maxval=0
        for e in arr:
            maxval=max(maxval,1+rec(elim_int(arr,e)))
        return maxval
    print(rec(g))