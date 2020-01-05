for _ in range(int(input())):
    n = int(input())
    arr = list(input())
    prev = n
    ans = 0
    for i in range(n-1,-1,-1):
        if arr[i]=='A':
            ans = max(ans,prev-i-1)
            prev = i
    print(ans)
