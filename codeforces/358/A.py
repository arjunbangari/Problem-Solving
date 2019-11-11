n = int(input())
arr = list(map(int, input().split()))

flag = 0

for i in range(n-1):
    for j in range(i+1,n-1):
        a,b = min(arr[i],arr[i+1]),max(arr[i],arr[i+1])
        c,d = min(arr[j],arr[j+1]),max(arr[j],arr[j+1])
        if a<c<b<d or c<a<d<b:
            flag=1
            break
    if flag==1:
        break

if flag==0:
    print("no")
else:
    print("yes")
