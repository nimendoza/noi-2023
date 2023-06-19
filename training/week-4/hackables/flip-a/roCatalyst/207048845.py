t = int(input())
for _ in range(t):
    n = int(input())
    A = input()
 
    count = 0
    PA = [0]
    currSum = 0
    ans = 0

    prevA = A[0]
    for i in range(n):
        currA = A[i]
        if currA != prevA:
            PA.append(currSum)
            prevA = currA

        if currA == "1":
            currSum -= 1
            count += 1
        else:
            currSum += 1
    PA.append(currSum)
    PAn = len(PA)
    
    for i in range(PAn):
        for j in range(i,PAn):
            ans = min(PA[j]-PA[i],ans)

    print(count + ans)