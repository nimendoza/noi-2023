t = int(input())

for _ in range(t):
    counts = list()

    TFmemo = {0:0}
    def maximize(bullets,TF,m):
        if bullets in TFmemo:
            return TFmemo[bullets]
        else:
            for t in TF:
                vi = TF[t][0]
                ci = TF[t][1]

                if bullets >= ci:
                    m = max(m,vi+maximize(bullets-ci,TF,m))

            TFmemo[bullets] = m
            return m
    
    n, d = map(int,input().split())
    TF = dict()
    for i in range(n):
        v, c = map(int,input().split())
        TF[i] = (v,c)
    
    ans = 0
    for i in range(1,d+1):
        ans = maximize(i,TF,0)
    print(ans)