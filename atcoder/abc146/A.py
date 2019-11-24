s = input()
arr = ['MON','TUE','WED','THU','FRI','SAT','SUN']
if s=='SUN':
  print(7)
else:
  print(arr.index('SUN') - arr.index(s))