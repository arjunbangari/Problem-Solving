n,a,b = map(int,input().split())

k = n//(a+b)

ans = k*a

p = n%(a+b)

ans += min(a,p)
print(ans)
