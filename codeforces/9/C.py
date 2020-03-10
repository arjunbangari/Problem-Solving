n = int(input())

s = list(str(n))
flag = 0
for i in range(len(s)):
    if flag==1:
        s[i]='1'
    else:
        if s[i]>'1':
            s[i] = '1'
            flag = 1
s1 = ''.join(x for x in s)

print(int(s1,2))
            
