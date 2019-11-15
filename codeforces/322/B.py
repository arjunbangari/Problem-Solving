r,g,b  = map(int, input().split())
ans0 = r//3 + g//3 + b//3
if r>=1 and g>=1 and b>=1:
    ans1 = 1 + max(0,(r-1)//3) + max(0,(g-1)//3) + max(0,(b-1)//3)
else:
    ans1 = 0
if r>=2 and g>=2 and b>=2:
    ans2 = 2 + max(0,(r-2)//3) + max(0,(g-2)//3) + max(0,(b-2)//3)
else:
    ans2 = 0
print(max(ans0,ans1,ans2))
