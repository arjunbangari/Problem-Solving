x,y = map(int, input().split())
n = int(input())
arr = [x-y,x,y,y-x,-x,-y]


x = arr[n%6]

print(x%1000000007)
