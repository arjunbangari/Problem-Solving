for _ in range(int(input())):
    a,b,c = map(int, input().split())
    brr = [[1,0,0],[0,1,0],[0,0,1],[0,1,1],[1,0,1],[1,1,0],[1,1,1]]
    arr = [a,b,c]
    arr.sort()
    ans = 0
    for i in brr:
        flag = 0
        for j in range(3):
            if i[j]==1 and arr[j]==0:
                flag = 1
        if flag ==0:
            ans +=1;
            for j in range(3):
                if i[j]==1:
                    arr[j]-=1
                
    print(ans)
        
