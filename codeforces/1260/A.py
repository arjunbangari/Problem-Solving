from math import ceil
n = int(input())

for i in range(n):
    c,s = map(int, input().split())
    temp = ((int(ceil(s/c)))**2)*(s%c) + ((s//c)**2)*(c-s%c)
    print(temp)

