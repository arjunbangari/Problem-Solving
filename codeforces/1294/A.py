for _ in range(int(input())):
    a,b,c,n = map(int, input().split())
    t = a+b+c+n
    if t%3==0:
        if (t//3)>=max(a,b,c):
            print("YES")
        else:
            print("NO")
    else:
        print("NO")
