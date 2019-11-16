n = int(input())
arr = list(map(int, input().split()))

mx = max(arr)
mn = min(arr)

if mx==mn:
    ans = (n*(n-1))//2
else:
    ans = arr.count(mx)*arr.count(mn)
print(mx-mn,ans)
