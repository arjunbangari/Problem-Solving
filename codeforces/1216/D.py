from math import gcd

n = int(input())
arr = list(map(int, input().split()))

maxi = max(arr)
add = maxi-arr[0] + maxi-arr[1]
gc = gcd(maxi-arr[0],maxi-arr[1])

for i in range(2,n):
    gc = gcd(gc,maxi-arr[i])
    add += maxi-arr[i]

print(add//gc , gc)    
    
