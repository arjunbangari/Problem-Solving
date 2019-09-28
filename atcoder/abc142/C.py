n = int(input())
arr = list(map(int, input().split()))

brr = [0]*n

for i in range(n):
    brr[arr[i]-1]=i+1
for i in brr:
    print(i,end=' ')
print()    
