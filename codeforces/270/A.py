for _ in range(int(input())):
    a = int(input())
    if a<60:
        print("NO")
    else:
        if 360%(180-a)==0:
            print("YES")
        else:
            print("NO")
