n = int(input())
arr = []
brr = []
ans = 0
for i in range(n):
    a,b = map(int, input().split())
    arr.append(a)
    brr.append(b)


for i in range(n):
    flag = 0
    for j in range(i):
        if brr[j]==arr[i]:
            flag = 1
            break
    if flag!=1:
        for k in range(i+1,n):
            if brr[k]==arr[i]:
                flag = 1
                break
    if flag==0:
        ans+=1
print(ans)
