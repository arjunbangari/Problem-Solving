for _ in range(int(input())):
    n = int(input())
    arr = [[0,0]]
    for i in range(n):
        arr.append(list(map(int, input().split())))
    arr.sort()
    s = ''
    flag = 0
    for i in range(1,n+1):
        if arr[i][1]<arr[i-1][1]:
            flag = 1
            break
        else:
            s += (arr[i][0]-arr[i-1][0])*'R' + (arr[i][1]-arr[i-1][1])*'U'
    if flag==0:
        print("YES")
        print(s)
    else:
        print("NO")
    
