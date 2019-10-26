da , db = map(int,input().split())
if db-da in [0,1] and (da!=0 and db!=0):
    if da==db:
        a = str(da) + '0'
        b = int(a)+1
    else:
        a = str(da)+'9'*2
        b = int(a)+1
    print(a,b)
elif db==1 and da==9:
    print(99,100)
else:
    print(-1)
