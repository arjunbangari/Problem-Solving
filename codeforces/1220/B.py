n = int(input())
arr = []
s = ''
for i in range(n):
    arr.append(list(map(int, input().split())))

for i in range(n):
    if i==0:
        temp = arr[1][0] * arr[2][0]
        arr[0][0] = int((temp//arr[1][2])**0.5)
        s+= str(arr[0][0]) + ' '
    elif i==(n-1):
        temp = arr[n-2][n-1] * arr[n-3][n-1]
        arr[n-1][n-1] = int((temp//arr[n-3][n-2])**0.5)
        s+= str(arr[n-1][n-1]) + ' '
    else:
        temp = arr[i-1][i] * arr[i+1][i]
        arr[i][i] = int((temp//arr[i-1][i+1])**0.5)
        s+= str(arr[i][i]) + ' '
print(s)        
        
    
