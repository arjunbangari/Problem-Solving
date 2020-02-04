for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    odd,even = 0,0
    for i in arr:
        if i%2==0:
            even+=1
        else:
            odd+=1

    if odd>0:
        if (odd%2==0 and even>0) or (odd%2!=0):
            print("YES")
        else:
            print("NO")
    else:
        print("NO")
