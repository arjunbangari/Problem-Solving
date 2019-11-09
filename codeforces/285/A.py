n, k = map(int, input().split())

i = n
m = k
while(m>0):
    print(i, end=' ')
    i-=1
    m-=1


temp = n-k

i = 1
while(temp>0):
    print(i, end=' ')
    i+=1
    temp-=1
print()
