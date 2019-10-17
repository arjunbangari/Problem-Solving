m,s = map(int, input().split())

if m==1 and s==0:
    print(0,0)
elif s<1 or s>9*m:
    print(-1,-1)
else:
    maxi = (s//9)*'9' + str(s%9) + (m-(s//9)-1)*'0'
    if len(maxi)>m:
        maxi = maxi[:-1]
 
    arr = [1] + [0]*(m-1)
 
    i = 1
    j = m-1
 
    while(i<s):
        if arr[j]==9:
            j-=1
        arr[j]+=1
        i+=1
    mini = ''.join(str(x) for x in arr)
    print(mini,maxi)
