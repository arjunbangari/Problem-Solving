a,b,c = map(int, input().split())
p = 4*a*b
q = (c-a-b)**2

if (c-a-b)<0:
    print("No")

elif p<q:
    print("Yes")
else:
    print("No")
