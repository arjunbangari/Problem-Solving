for _ in range(int(input())):
    n,x,c,d = map(int, input().split())
    a,b = min(c,d),max(c,d)
    if (a-1)<=x:
        x -= (a-1)
        a = 1
    else:
        a = a-x
        x = 0
    if (n-b)<=x:
        x-=(n-b)
        b = n
    else:
        b = b+x
        x = 0
    print(b-a)
