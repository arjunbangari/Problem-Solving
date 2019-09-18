n = int(input())
s = input()
zero = s.count('z')
one = s.count('n')

ans = one*'1 ' + zero*'0 '
print(ans)
