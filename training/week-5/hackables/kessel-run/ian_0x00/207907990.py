n,h=map(int,input().split())
c=sorted([int(x) for x in input().split()],reverse=True)
sum=count=i=0
while sum<h:
    if sum+c[i]<=h:
        sum+=c[i]
        count+=1
    else:i+=1
print(count)