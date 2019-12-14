for _ in range(int(input())):
    n = int(input())
    l = len(str(n))
    ans = (l-1)*9
    num = str(n)
    if l==1:
        ans += n
    else:
        if num.count(num[0])==l:
            ans += int(num[0])
        else:
            i=1
            while(i<l and num[i]==num[i-1]):
                i+=1
            if num[i]>num[i-1]:
                ans+= int(num[0])
            else:
                ans+= int(num[0])-1
                
                    
                    
    print(ans)
    
