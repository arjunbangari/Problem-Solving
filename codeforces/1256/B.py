for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    brr = [0]*(n-1)

    for i in range(n-2,-1,-1):
        if arr[i]>arr[i+1]:
            arr[i], arr[i+1] = arr[i+1], arr[i]
            brr[i] = 1

    for i in range(n-1):
        if arr[i]>arr[i+1] and brr[i]==0:
            arr[i], arr[i+1] = arr[i+1], arr[i]
            brr[i] = 1
    print(*arr)            
            
