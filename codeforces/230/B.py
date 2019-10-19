mem = {}

n = 10**6 
prime = [True for i in range(n+1)] 
p = 2
while (p * p <= n):  
    if (prime[p] == True): 
        for i in range(p * p, n+1, p): 
            prime[i] = False
    p += 1

for p in range(2, n): 
    if prime[p]: 
        mem[p**2] = 1
        

num = int(input())
arr = list(map(int, input().split()))

for i in arr:
    if i in mem:
        print("YES")
    else:
        print("NO")
    


  
