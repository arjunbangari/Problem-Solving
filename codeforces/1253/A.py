for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    brr = list(map(int,input().split()))
    for i in range(n):
        brr[i]-=arr[i]
    s = list(set(brr))
    l = len(s)
    if l>2:
        print("NO")
    else:
        if l==1:
            if s[0]>=0:
                print("YES")
            else:
                print("NO")
        elif l==2:
            if 0 not in s:
                print("NO")
            else:
                s.sort()
                if s[1]<0:
                    print("NO")
                else:
                    left = brr.index(s[1])
                    right = brr[::-1].index(s[1])
                    if 0 in brr[left:n-right-1]:
                        print("NO")
                    else:
                        print("YES")
            
            
    

            
