def issub(string1, string2, m, n):
    if m == 0:    return True
    if n == 0:    return False
    if string1[m-1] == string2[n-1]: 
        return issub(string1, string2, m-1, n-1) 
    return issub(string1, string2, m, n-1) 

s = input()
t = input()

if issub(t,s,len(t),len(s)):
    print("automaton")
else:
    dc = {}
    for i in s:
        if i in dc:
            dc[i]+=1
        else:
            dc[i] = 1
    flag = 0
    for i in t:
        if i in dc and dc[i]>0:
            dc[i]-=1
        else:
            flag = 1
            break
    if flag==0:
        if len(t)==len(s):
            print("array")
        else:
            print("both")
    else:
        print("need tree")
            
    
