l,r = map(int, input().split())
ans = -1
for i in range(l,r+1):
    if len(set(str(i)))==len(str(i)):
        ans = i
        break
print(ans)
