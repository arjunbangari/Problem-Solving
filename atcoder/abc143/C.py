n = int(input())
s = input()
ans = 0
i=0
while(i<n):
    j= i+1
    while(j<n and s[i]==s[j]):
        j+=1
    i = j
    ans+=1

print(ans)    
    
    

