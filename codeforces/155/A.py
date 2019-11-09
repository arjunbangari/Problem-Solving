n = int(input())
arr = list(map(int, input().split()))
ans = 0
mx = arr[0]
mn = arr[0]

for i in range(1,n):
    if arr[i]>mx or arr[i]<mn:
        ans += 1
    if arr[i]>mx:
        mx= arr[i]
    elif arr[i]<mn:
        mn = arr[i]
print(ans)
