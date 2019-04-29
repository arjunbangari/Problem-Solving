n,m,r = map(int, input().split())
arr1 = list(map(int, input().split()))
arr2 = list(map(int, input().split()))
count = r//min(arr1)
num = r-count*min(arr1)
ans = count*max(arr2) + num
print(ans if ans>r else r)

        
