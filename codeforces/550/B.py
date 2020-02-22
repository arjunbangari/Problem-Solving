from itertools import combinations

n,l,r,x = map(int, input().split())
arr = list(map(int, input().split()))
ans = 0
for i in range(2,n+1):
    brr = list(combinations(arr,i))
    for i in brr:
        s = sum(i)
        mn,mx = min(i), max(i)
        if s>=l and s<=r and (mx-mn)>=x:
            ans+=1
print(ans)
