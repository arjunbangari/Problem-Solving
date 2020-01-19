n = int(input())
arr = list(map(int, input().split()))

ind = [0]*(n+1)
for i in range(n):
    ind[arr[i]] = i
temp = 100000000
ans = 0
for i in range(1,n+1):
    if ind[i]<temp:
        ans+=1
        temp = ind[i]
print(ans)
