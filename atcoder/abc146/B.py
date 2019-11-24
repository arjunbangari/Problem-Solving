n = int(input())
s = list(input())

for i in range(len(s)):
    s[i] = chr(65 + (ord(s[i])-65 + n)%26)

print(''.join(x for x in s))
