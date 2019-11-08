from collections import Counter
import math

n = int(input())
arr = list(map(int, input().split()))

brr = Counter(arr)

ans = 0
if 4 in brr:
    ans += brr[4]
    
if 3 in brr:
    ans += brr[3]
    if 1 in brr:
        brr[1] -= min(brr[1],brr[3])
    
if 2 in brr:
    ans += int(math.ceil(brr[2]/2))
    if brr[2]%2!=0:
        if 1 in brr and brr[1]>0:
            brr[1] -= min(brr[1],2)
    
if 1 in brr:
    ans += int(math.ceil(brr[1]/4))
  
print(ans)
