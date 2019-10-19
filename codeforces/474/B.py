from bisect import bisect_left

n = int(input())
arr = list(map(int,input().split()))

for i in range(1,n):
    arr[i] += arr[i-1]

m = int(input())
q = list(map(int, input().split()))

for i in range(m):
    ans = bisect_left(arr,q[i])
    print(ans+1)
    


  
