
n,t=map(int,raw_input().split())
a=map(int,raw_input().split())

c=1

print len(a)
while(c!=t and c-1 < len(a)):
	c+=a[c-1]
if c==t:
	print 'YES'
else:
	print 'NO'

