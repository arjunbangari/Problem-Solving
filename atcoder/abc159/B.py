s = input()
n = len(s)
if s==s[::-1]:
    t = s[:n//2]
    p = s[n//2 + 1 :]
    if t==t[::-1] and p==p[::-1]:
        print("Yes")
    else:
        print("No")
else:
    print("No")
