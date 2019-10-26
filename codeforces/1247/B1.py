for _ in range(int(input())):
    n,k,d = map(int, input().split())
    arr = list(map(int, input().split()))
    mem = {}
    for j in range(d):
        try:
            mem[arr[j]]+=1
        except:
            mem[arr[j]] = 1
    ans = len(mem.keys())
    temp = ans
    i = 0
    j = d

    while(j<n):
        if arr[j] in mem:
            if mem[arr[j]]==0:
                temp+=1
            mem[arr[j]]+=1
        else:
            mem[arr[j]] = 1
            temp+=1
        mem[arr[i]]-=1
        if mem[arr[i]]==0:
            temp-=1
        ans = min(ans,temp)
        j+=1
        i+=1
    print(ans)        
            
