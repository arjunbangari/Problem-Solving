for _ in range(int(input())):
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))

    if (max(arr)-min(arr))>(2*k):
        print(-1)
    else:
        print(min(arr)+k)
