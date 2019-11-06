for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))

    arr.sort(reverse=True)
    i=0
    flag = 0
    while(i<n):
        if arr[i]>=(i+1):
            ans = i
            i+=1
        else:
            ans = i
            flag = 1
            break
    if flag==0:
        print(min(n,arr[-1]))
    else:
        print(min(ans,arr[ans-1]))
        
            
