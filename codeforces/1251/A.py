for _ in range(int(input())):
    s = input()
    n = len(s)
    if n==1:
        print(s)
    else:
        a = set()
        i=0
        while(i<n-1):
            if(s[i]==s[i+1]):
                j = i+1
                while(j<n and s[j]==s[i]):
                    j+=1
                if(j-i)%2!=0:
                    a.add(s[i])
                i = j
            else:
                a.add(s[i])
                i+=1
        if s[n-1]!=s[n-2]:
            a.add(s[n-1])   
        arr = list(sorted(a))
        print(''.join(str(x) for x in arr))
                
       
