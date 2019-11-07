n = int(input())
arr = list(map(int, input().split()))
ones = arr.count(1)

if ones==0:
    print(n)
elif ones==n:
    print(n-1)
else:
    brr = [1 if arr[i]==0 else -1 for i in range(n)]
    maxsum = 0
    temp = 0
    for i in range(n):
        temp = max(brr[i], temp + brr[i])
        maxsum = max(maxsum, temp)
    print(ones + maxsum)
    
