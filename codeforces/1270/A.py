for _ in range(int(input())):
    n,k1,k2 = map(int, input().split())
    arr = list(map(int, input().split()))
    brr = list(map(int, input().split()))
    max1 = max(arr)
    max2 = max(brr)
    if max1>max2:
        print("YES")
    else:
        print("NO")
