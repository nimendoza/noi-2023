n=int(input());count=0
graph={x:[] for x in range(1,n+1)}
for i,e in enumerate(input().split()):
    graph[i+2].append(int(e))
    graph[int(e)].append(i+2)
while n>0:
    target=min(graph,key=lambda v:len(graph[v]))
    n-=len(graph[target])+1;count+=1
    for a in graph[target]:
        for b in graph[a]:
            graph[b].remove(a)
        del graph[a]
    del graph[target]
print(count)