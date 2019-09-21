for _ in range(int(input())):
    c,m,x = map(int,input().split())
    ans = 0
    mini = min(c,m,x)
    if mini!=x:
        ans += mini
    else:
        c -= x
        m -= x
        ans += x
        mini = min(c,m)
        maxi = max(c,m)
        if maxi>=2*mini:
            ans+=mini
        else:
            ans += (c+m)//3
    print(ans)
