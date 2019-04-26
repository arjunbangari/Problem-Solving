n = int(input())
arr = [n]
count = 1
while True:
    n +=1
    n = int(str(n).rstrip('0'))
    if n in arr:
        break
    else:
        arr.append(n)
        count+=1
print(count)    
