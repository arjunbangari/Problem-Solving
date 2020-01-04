n,m = map(int, input().split())
arr = list(map(str, input().split()))
brr = list(map(str, input().split()))
q = int(input())

for _ in range(q):
    y = int(input())
    if y<=n:
        ind1 = y-1
    else:
        ind1 = y%n - 1
    if y<=m:
        ind2 = y-1
    else:
        ind2 = y%m -1
    print(arr[ind1] + brr[ind2])
