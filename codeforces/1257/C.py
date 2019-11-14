for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    mem = {}

    for i in range(n):
        try:
            mem[arr[i]].append(i)
        except:
            mem[arr[i]] = [i]

    sub = list(mem.values())
    ans = 10**7
    for i in sub:
        l = len(i)
        if l>1:
            for j in range(1,l):
                if (i[j]-i[j-1])<ans:
                    ans = (i[j]-i[j-1])
    if ans==10**7:
        print(-1)
    else:
        print(ans+1)
            
    
