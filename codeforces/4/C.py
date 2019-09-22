mem = {}

for _ in range(int(input())):
    s = input()
    if s not in mem:
        mem[s] = 0
        print("OK")
    else:
        mem[s]+=1
        num = mem[s]
        mem[s+str(num)] = 0
        print(s+str(num))        
        
    
