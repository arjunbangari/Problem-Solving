n = int(input())

for i in range(1,n+1):
    s = ''
    for j in range(1,n+1):
        if (i+j)%2==0:
            s+='W'
        else:
            s += 'B'
    print(s)            
        
        
