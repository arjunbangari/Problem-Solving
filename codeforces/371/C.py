s = input()
cb = s.count('B')
cs = s.count('S')
cc = s.count('C')

nb,ns,nc = map(int, input().split())
pb,ps,pc = map(int, input().split())
r = int(input())

left = 0
right = 10**14

while (left+1)<right:
    mid = (left + right)//2
    value = max(0,cb*mid - nb)*pb + max(0,cs*mid - ns)*ps + max(0,cc*mid - nc)*pc
    if value<=r:
        left = mid
    else:
        right = mid
print(left)
