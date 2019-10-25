num = int(input())
n = list(input())
arr = ['0']+ list(map(str, input().split()))
i = 0
while(i<num):
    if arr[int(n[i])]>n[i]:
        n[i] = arr[int(n[i])]
        i+=1
        while(i<num and arr[int(n[i])]>=n[i]):
            n[i] = arr[int(n[i])]
            i+=1
        break    
    i+=1

print(''.join(x for x in n))    
