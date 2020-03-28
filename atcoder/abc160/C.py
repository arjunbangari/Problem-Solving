k,n = map(int, input().split())
arr = list(map(int, input().split()))
mx = abs(k-arr[-1]+arr[0])
for i in range(1,n):
    mx = max(mx, abs(arr[i]-arr[i-1]))

print(k-mx)
