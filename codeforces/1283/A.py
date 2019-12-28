for _ in range(int(input())):
    h,m = map(int, input().split())
    if m==0:
        ans = (24-h)*60
    else:
        ans = 60-m
        h+=1
        ans += (24-h)*60
    print(ans)
