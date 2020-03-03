for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    brr = list(map(int, input().split()))
    arr.sort()
    brr.sort()
    print(*arr)
    print(*brr)
