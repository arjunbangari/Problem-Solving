for _ in range(int(input())):
    n = int(input())
    s = input()
    t = input()
    count = 0
    temp = []
    flag = 0
    for i in range(n):
        if s[i]!=t[i]:
            count+=1
            temp.append([s[i],t[i]])
        if count>2:
            flag = 1
            break
    if flag==1:
        print("No")
    elif count==2:
        if temp[0][0]==temp[1][0] and temp[0][1]==temp[1][1]:
            print("Yes")
        else:
            print("No")
    else:
        print("No")
