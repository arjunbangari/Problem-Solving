for _ in range(int(input())):
    x,y = map(int, input().split())
    if x==y:
        ans = "YES"
    elif x==1 and y>1:
        ans = "NO"
    elif x==2 and y>3:
        ans = "NO"
    elif x==3 and y>3:
        ans = "NO"
    else:
        ans = "YES"
    
    
    print(ans)
        
