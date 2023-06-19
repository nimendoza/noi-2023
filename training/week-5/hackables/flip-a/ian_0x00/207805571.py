t=int(input())
for _ in range(t):
    n=int(input())
    arr=[]
    arr=[int(x) for x in input()]
    ans=999999999
    for i in range(n):
        for j in range(i,n):
            tmp=0
            for k in range(n):
                tmp+=(1-arr[k] if i<=k<=j else arr[k])
            ans=min(ans,tmp)
    print(ans)