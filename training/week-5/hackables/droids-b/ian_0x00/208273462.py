for _ in range(int(input())):
    n,k=map(int,input().split())
    a=[[int(x) for x in input().split()],
        [int(x) for x in input().split()]]
    m={}
    def amog(_n,_a,_k):
        if m.get(gus:=tuple([tuple(_a[0]),tuple(_a[1])])):
            return m[gus]
        ans=0
        if _k==0:return ans
        for i in range(n):
            if _a[0][i]>0:
                cp=[[y for y in x] for x in _a]
                cp[0][i]=0
                ans=max(ans,amog(_n,cp,_k-1)+_a[0][i])
            if _a[1][i]>0 and _a[0][i]==0:
                cp=[[y for y in x] for x in _a]
                cp[1][i]=0
                ans=max(ans,amog(_n,cp,_k-1)+_a[1][i])
        m[gus]=ans;return ans
    print(amog(n,a,k))