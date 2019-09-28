import math
def prime(n):
    set1 = set()
    while n % 2 == 0: 
        set1.add(2) 
        n = n / 2
    for i in range(3,int(math.sqrt(n))+1,2): 
        while n % i== 0: 
            set1.add(i)
            n = n / i 
    if n > 2: 
        set1.add(n)
    return set1

a,b = map(int, input().split())
ans1 = prime(a)
ans2 = prime(b)
ans3 = ans1.intersection(ans2)
print(len(ans3)+1)
