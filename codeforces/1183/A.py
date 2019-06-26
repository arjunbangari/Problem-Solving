a = int(input())

while(True):
    arr = [int(i) for i in str(a)]
    if sum(arr)%4==0:
        print(a)
        break
    else:
        a+=1
