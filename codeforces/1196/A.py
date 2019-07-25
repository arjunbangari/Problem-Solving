for _ in range(int(input())):
    arr = list(map(int, input().split()))
    arr.sort()
    num = arr[2] - (arr[1]-arr[0])
    print((num//2) + arr[1])
