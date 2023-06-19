t = int(input())
for _ in range(t):
    n = int(input())
    A = input()

    if n > 1:
        count = 0
        ans1 = 0
        

        currSum = 0
        prevA = A[0]
        PA = [0]

        shortAi = 0
        shortA = [0]
        for i in range(n):
            currA = A[i]
            if currA != prevA:
                shortA.append(shortAi)
                PA.append(currSum)
                shortAi = 0
                prevA = currA

            if currA == "1":
                currSum -= 1
                shortAi -= 1
                count += 1
            else:
                currSum += 1
                shortAi += 1
        shortA.append(shortAi)
        PA.append(currSum)
        PAn = len(PA)
        
        BestI = 0
        BestJ = 0
        for i in range(PAn):
            for j in range(i,PAn):
                prev = ans1
                ans1 = min(PA[j]-PA[i],ans1)
                if ans1 != prev:
                    BestI = i
                    BestJ = j

        PA = []
        currSum = 0
        for i in range(PAn):
            if BestI < i <= BestJ:
                currSum -= shortA[i]
            else:
                currSum += shortA[i]
            PA.append(currSum)
        
        ans2 = 0
        for i in range(PAn):
            for j in range(i,PAn):
                ans2 = min(PA[j]-PA[i],ans2)

        print(count + ans1 + ans2)
    elif A[0] == "1":
        print(1)
    else:
        print(0)