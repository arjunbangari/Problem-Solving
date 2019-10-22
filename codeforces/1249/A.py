for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort()
    flag = 0

    for i in range(1,n):
        if (arr[i]-arr[i-1])==1:
            flag = 1
            break
    if flag==1:
        print(2)
    else:
        print(1)
