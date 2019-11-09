s,n = map(int,input().split())
arr = []


for i in range(n):
    arr.append(list(map(int, input().split())))

arr.sort()

flag  = 0

for i in range(n):
    if s>arr[i][0]:
        s += arr[i][1]
    else:
        flag = 1
        break

if flag==1:
    print("NO")
else:
    print("YES")
    
