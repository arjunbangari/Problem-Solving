n,k = map(int, input().split())
s = input()
arr = list(map(str, input().split()))
mp = {}
for i in arr:
    mp[i] = 1

i = 0
j = 0
ans = 0
while i<n:
    if s[i] in mp:
        j = i+1
        while j<n:
            if s[j] in mp:
                j+=1
            else:
                break
        temp = j-i
        ans += (temp*(temp+1))//2
        i = j
    else:
        i+=1
print(ans)
    
