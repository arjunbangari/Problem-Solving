s = input()
l = len(s)
ans = -1

for i in range(l):
    temp = int(s[i])
    if temp%8==0:
        ans = temp
        break
    for j in range(i+1,l):
        temp = int(s[i]+s[j])
        if temp%8==0:
            ans = temp
            break
        for k in range(j+1,l):
            temp = int(s[i] + s[j] + s[k])
            if temp%8==0:
                ans = temp
                break
if ans==-1:
    print("NO")
else:
    print("YES")
    print(ans)
