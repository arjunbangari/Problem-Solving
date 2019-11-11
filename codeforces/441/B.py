n,v = map(int, input().split())
arr = [0]*3002

for _ in range(n):
    a,b = map(int, input().split())
    arr[a] += b

x = v
ans = 0
prev = 0
for i in range(1,3002):
    x = max(x-prev,0)
    ans += (v-x)
    if arr[i]<=x:
        ans += arr[i]
        prev = 0
    else:
        ans += x
        prev = arr[i]-x
    x = v
print(ans)
    
    
    
    
