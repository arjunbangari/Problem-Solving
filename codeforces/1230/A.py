from itertools import combinations
arr  = list(map(int, input().split()))
ans = "NO"
s = sum(arr)
for i in range(2,4):
    brr = list(combinations(arr,i))
    brr = [sum(i) for i in brr]
    for j in brr:
        if (s-j)==j:
            ans = "YES"

print(ans)            
    

