a,b,c = map(int, input().split())

ans = []

for i in range(1,82):
    temp = b*(i**a) + c
    if temp>0 and temp<10**9:
        s = str(temp)
        l = len(s)
        p = 0
        for j in range(l):
            p += int(s[j])
        if p==i:
            ans.append(temp)

ans.sort()

print(len(ans))
print(*ans)
