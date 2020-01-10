from itertools import permutations

n = int(input())
prr = list(map(int, input().split()))
qrr = list(map(int, input().split()))

arr = list(permutations(prr))
arr.sort()
for i in range(len(arr)):
    arr[i] = list(arr[i])

ans = arr.index(prr) - arr.index(qrr)
print(abs(ans))
