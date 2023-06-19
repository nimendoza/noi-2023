t = int(input())
for _ in range(t):
    n = int(input())
    A = input()

    count = 0
    PA = [0]
    currSum = 0
    ans = 0
    for i in range(n):
        if A[i] == "1":
            currSum -= 1
            count += 1
        else:
            currSum += 1
        
        ans = min(ans,currSum)
        PA.append(currSum)
    
    for i in range(n+1):
        for j in range(i+1,n+1):
            ans = min(PA[j]-PA[i],ans)

    print(count + ans)