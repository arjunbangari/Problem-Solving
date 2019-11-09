n,m = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()

ans = 0
i = 0
while(i<m and arr[i]<0):
    ans -= arr[i]
    i+=1
print(ans)
