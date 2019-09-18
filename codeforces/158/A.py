n,k = map(int, input().split())
arr = list(map(int, input().split()))
ans = 0
if arr[k-1]>0:
    if k==n:
        ans = n
    else:
        ans = arr[k:].count(arr[k-1]) + k
else:
    for i in range(k-1):
        if arr[i]>0:
            ans+=1
print(ans)            
    
