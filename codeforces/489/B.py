from collections import Counter
n = int(input())
arr = list(map(int, input().split()))
m = int(input())
brr = list(map(int, input().split()))

mem = Counter(arr)

ans = 0
brr.sort()
for i in brr:
    if (i-1) in mem and mem[i-1]>0:
        ans += 1
        mem[i-1]-=1
    elif i in mem and mem[i]>0:
        ans+=1
        mem[i]-=1
    elif (i+1) in mem and mem[i+1]>0:
        ans+=1
        mem[i+1]-=1

print(ans)        
