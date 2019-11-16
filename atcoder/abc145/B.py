n = int(input())
s = input()
l = len(s)
if l%2!=0:
    print("No")
else:
    if s[:l//2]==s[l//2:]:
        print("Yes")
    else:
        print("No")
