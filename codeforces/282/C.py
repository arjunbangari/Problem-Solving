a = input()
b = input()

l1 = len(a)
l2 = len(b)
t1 = '1' in a
t2 = '1' in b

if l1!=l2 or t1!=t2:
    print("NO")
else:
    print("YES")
