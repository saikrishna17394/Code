#! python
import sys
from math import pow

s=raw_input()
# print s

t=int(s)
# print t

while (t>0) :
	s=raw_input()
	n,b=[int(x) for x in s.split(' ')]

	q1=1/b
	r1=1%b

	q1=q1%2

	# print q1
	for i in range(2,n+1):
		q2=i/b
		r2=i%b
		q2=q2%2

		q1=q1*q2+q1*r2+q2*r1
		q1=q1+(r1*r2)/b
		q1=q1%2
		r1=(r1*r2)%b
		# print q1

	if(q1==0):
		print "Even"
	else :
		print "Odd"
	t=t-1