from math import log

def isa(n):
    sm = log(n,3)
    if (sm).is_integer():
        ans = 3**int(sm)
    else:
        sm = int(sm)
        sumt = 0
        for i in range(sm):
            sumt += 3**i
        if (n-3**sm)>sumt:
            ans = 3**(sm+1)
        else:
            ans = 3**sm
            temp = n- 3**sm
            ans += isa(temp)
    return ans            
    

for _ in range(int(input())):
    n = int(input())        
    print(isa(n))                    
                
            
        
