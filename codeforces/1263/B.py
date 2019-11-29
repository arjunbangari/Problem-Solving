
for _ in range(int(input())):
    n = int(input())
    arr = []
    for i in range(n):
        arr.append(input())

    p = '0123456789'
    ans = 0
    for i in range(n-1):
        if arr[i] in arr[i+1:]:
            ans +=1
            brr = []
            for j in range(n):
                brr.append(arr[j][0])
            for j in p:
                if j not in brr:
                    arr[i] = j + arr[i][1:]
                    break
    print(ans)       
    for i in arr:
        print(i)
    
            
    
        
