n = int(input())
arr = []
mem = {}

for i in range(n):
    a,b = map(int, input().split())
    arr.append([a,b])

arr.sort()

temp = 0

for i in range(n):
    if arr[i][1]>=temp:
        temp = arr[i][1]
    else:
        temp = arr[i][0]
print(temp)
