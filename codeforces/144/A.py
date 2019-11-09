n = int(input())
arr = list(map(int, input().split()))
mx = max(arr)
mn = min(arr)

indmx = arr.index(mx)
indmn = arr[::-1].index(mn)

if (indmx+indmn)>=n:
    ans = indmx + indmn -1
else:
    ans = indmx + indmn

print(ans)
