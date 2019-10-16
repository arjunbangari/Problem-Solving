from math import floor,ceil
n = int(input())
temp = 0
brr = []
for i in range(n):
    val = int(input())
    if val%2==0:
        brr.append(val//2)
    else:
        if temp==0:
            ans = int(floor(val/2))
            temp = 1
        else:
            ans = int(ceil(val/2))
            temp = 0
        brr.append(ans)

for i in range(n):
    print(brr[i])
    
