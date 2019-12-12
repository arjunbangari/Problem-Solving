for _ in range(int(input())):
    arr = list(map(int, input().split()))
    arr.sort()
    arr[0] = min(arr[0]+1,arr[2])
    arr[2] = max(arr[2]-1,arr[0])
    ans = 2*(arr[2]-arr[0])
    print(ans)
    
