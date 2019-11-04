for _ in range(int(input())):
    a,b,n,s = map(int, input().split())
    if (n*a + b)<s:
        ans = "NO"
    else:
        temp = s//n
        if (s-temp*n)<=b:
            ans = "YES"
        else:
            ans = "NO"
    print(ans)            
