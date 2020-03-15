n = int(input())
s = list(input())

if n==1:
    print(1)
else:
    i,j = 0,1
    while(i<n-1 and j<n):
        if(s[i]==s[j]):
            s[j]=''
            j+=1
        else:
            i = j+1
            j += 2
    res = ''.join(x for x in s)
    l = len(res)
    if l%2==1:
        l -= 1
    print(n-l)
    print(res[:l])

