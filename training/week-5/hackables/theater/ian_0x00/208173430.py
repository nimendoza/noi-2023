t=int(input())
for _ in range(t):
    n=int(input());g=[]
    for _ in range(n):
        a,b=map(int,input().split())
        g.append((a,b))
    # def elim_int(arr,ele):
    #     return [x for x in arr if x[1]<ele[0] or x[0]>ele[1]]
    # def rec(arr):
    #     maxval=0
    #     for e in arr:
    #         maxval=max(maxval,1+rec(elim_int(arr,e)))
    #     print(arr,maxval)
    #     return maxval
    # print(rec(g))
    g=sorted(g,key=lambda x:x[1])
    ans=[g[0]]
    for i in range(1,n):
        if ans[-1][1]<g[i][0]:
            ans.append(g[i])
    print(len(ans))