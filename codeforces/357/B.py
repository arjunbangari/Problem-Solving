n,m = map(int, input().split())
arr = [0]*(n+1)

for i in range(m):
    a,b,c = map(int, input().split())
    if arr[a]==0 and arr[b]==0 and arr[c]==0:
        arr[a] = 1
        arr[b] = 2
        arr[c] = 3
    else:
        brr = [1,2,3]
        if arr[a]!=0:
            brr.remove(arr[a])
        if arr[b]!=0:
            brr.remove(arr[b])
        if arr[c]!=0:
            brr.remove(arr[c])
        if arr[a]==0:
            arr[a] = brr[0]
            brr.remove(brr[0])
        if arr[b]==0:
            arr[b] = brr[0]
            brr.remove(brr[0])
        if arr[c]==0:
            arr[c] = brr[0]
            brr.remove(brr[0])


print(*arr[1:])
            
        
