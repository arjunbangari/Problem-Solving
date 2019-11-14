for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    mem = {}
    ans = 10**7
    for i in range(n):
        try:
            ans = min(i-mem[arr[i]]+1,ans)
            mem[arr[i]] = i
        except:
            mem[arr[i]] = i
    if ans==10**7:
        print(-1)
    else:
        print(ans)
            
    
