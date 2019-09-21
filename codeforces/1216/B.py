mem = {}

n = int(input())
arr = list(map(int, input().split()))

for i in range(n):
    if arr[i] in mem:
        mem[arr[i]].append(i+1)
    else:
        mem[arr[i]] = [i+1]

arr.sort(reverse=True)
j=0
ans = 0
for i in range(n):
    ans += (arr[i]*j)+1
    j+=1

print(ans)

i = 0
while(i<n):
    p = len(mem[arr[i]])
    for j in mem[arr[i]]:
        print(j,end=" ")
    i+=p

print()    
