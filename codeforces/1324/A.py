for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    odd = 0
    even = 0
    for i in arr:
        if i%2==0:
            even += 1
        else:
            odd+=1
    if odd==0 or even==0:
        print("YES")
    else:
        print("NO")
