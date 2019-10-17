n = int(input())
arr = list(map(int, input().split()))
for i in range(n):
    arr[i] = arr[i]%2

if arr.count(1)>arr.count(0):
    print(arr.index(0)+1)
else:
    print(arr.index(1)+1)
