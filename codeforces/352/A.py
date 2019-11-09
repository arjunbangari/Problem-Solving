n = int(input())
arr = list(map(int, input().split()))
five = arr.count(5)
zero = arr.count(0)

if zero==0:
    print(-1)

else:
    ans = '5'*((five//9)*9) + '0'*zero
    print(int(ans))
