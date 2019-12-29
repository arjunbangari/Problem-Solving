a,b,k = map(int, input().split())
temp = min(a,k)
ans = temp
k -= temp
a-=temp
temp = min(b,k)
b -= temp

print(a,b)

