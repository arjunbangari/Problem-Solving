from math import log
for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    
    arr2 = [0]*12
    for i in arr:
        if i<=2048:
            x = int(log(i,2))
            arr2[x]+=1
        else:
            continue
    

    for i in range(11):
        arr2[i+1] += arr2[i]//2
    if arr2[11]>=1:
        print("YES")
    else:
        print("NO")
