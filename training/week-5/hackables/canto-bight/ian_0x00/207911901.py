for _ in range(int(input())):
    n,a=map(int,input().split())
    c=[int(x) for x in input().split()]
    dp=[[0 for _ in range(a+1)] for _ in range(n+1)]
    for i in range(1,n+1):
        for j in range(1,a+1):
            if j-c[i-1]>=0:
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-c[i-1]]+c[i-1])
            else:dp[i][j]=dp[i-1][j]
    print(dp[n][a])