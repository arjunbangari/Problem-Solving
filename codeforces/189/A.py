n,a,b,c = map(int, input().split())

mem = {}
mem[0] = 0

for i in range(1,n+1):
    try:
        mem[i-a]
    except:
        mem[i-a]=-1
    try:
        mem[i-b]
    except:
        mem[i-b] = -1
    try:
        mem[i-c]
    except:
        mem[i-c] = -1
    
    temp = max(mem[i-a],mem[i-b],mem[i-c])

    if temp==-1:
        mem[i] = -1
    else:
        mem[i] = temp+1

print(mem[n])
