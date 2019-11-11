n,m = map(int, input().split())
arr = [i for i in range(n+1)]
mem = {}
for i in range(m):
    a,b = map(int, input().split())
    if arr[a] in mem:
        mem[arr[a]].append(arr[b])
        arr[b] = arr[a]
    elif arr[b] in mem:
        mem[arr[b]].append(arr[a])
        arr[a] = arr[b]
    else:
        mem[arr[a]] = [arr[a],arr[b]]
        arr[b] = arr[a]

for i in mem.keys():
    arr[i] = 0


brr = []
for i in range(1,n+1):
    if arr[i]==i:
        brr.append(i)
l1 = len(brr)
crr = list(mem.values())
l2 = len(crr)

for i in range(l2):
    crr[i] = list(set(crr[i]))

flag = 0
for i in crr:
    if len(i)>3:
        flag = 1
        break
    elif len(i)==3:
        continue
    else:
        try:
            i.append(brr[0])
            brr = brr[1:]
        except:
            flag = 1
            break

if flag!=1:
    for i in crr:
        print(*i)
    l1 = len(brr)
    for j in range(0,l1,3):
        print(brr[j],brr[j+1],brr[j+2])
else:
    print(-1)


