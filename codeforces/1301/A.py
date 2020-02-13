for _ in range(int(input())):
    a = input()
    b = input()
    c = input()
    l = len(a)
    flag = 0
    for i in range(l):
        if c[i]==a[i] or c[i]==b[i]:
            continue
        else:
            flag = 1
            break
    if flag:
        print("NO")
    else:
        print("YES")
