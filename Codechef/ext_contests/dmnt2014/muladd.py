#! python
import sys
from math import pow

s=raw_input()
# print s

t=int(s)
# print t

while (t>0) :
	s=raw_input()
	n=int(s)

	if (n>1000000):
		print "0"
	else :
		a=1
		b=1

		for i in range(1,n+1):
			a=(a*i)%329885391853
			b=(b*a)%329885391853

		print b
	t=t-1