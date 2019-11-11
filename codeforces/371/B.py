def func(n):
    n2 = 0
    n3 = 0
    n5 = 0
    while(n%2==0):
        n = n//2
        n2+=1
    while(n%3==0):
        n = n//3
        n3+=1
    while(n%5==0):
        n = n//5
        n5 += 1
    return (n,n2,n3,n5)
        


a,b = map(int, input().split())
aleft,a2,a3,a5 = map(int, func(a))
bleft,b2,b3,b5 = map(int, func(b))

if aleft==bleft:
    ans = abs(a2-b2) + abs(a3-b3) + abs(a5-b5)
    print(ans)
else:
    print(-1)

