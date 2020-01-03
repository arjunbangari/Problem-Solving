from math import ceil
r,x1,y1,x2,y2 = map(int, input().split())
dist = ((x2-x1)**2 + (y2-y1)**2)**(0.5)
ans = int(ceil(dist/(2*r)))
print(ans)
