n,k = map(int, input().split())
arr = list(map(int, input().split()))
count = 0
for i in arr:
    if i>=k:
        count+=1
print(count)        
