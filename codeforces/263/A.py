arr = []
for i in range(5):
    arr.append(list(map(int, input().split())))

for i in range(5):
    for j in range(5):
        if arr[i][j]==1:
            l,r = i,j
            break

ans = abs(l-2) + abs(r-2)
print(ans)
            
