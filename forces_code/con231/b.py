#! python
import sys
from math import pow

s=raw_input()

p,x=[int(x) for x in s.split(' ')]
# print s

val=10*x-1
num=1
rem=1

for i in range(1,p):
	num=num*10
	rem=(rem*10)%val

a1=num*10
a2=num
num=num-x

rem+=val-x
rem%=val

# print num

num1=num

for b in range(1,9):
	# num1=num*b
	if((rem*b)%val==0):
		ans=num1/val
		ans=ans*10+b
		# print ans
		# print a1
		# print a2
		if((ans>=a2) & (ans<a1)):
			print ans
			sys.exit()
	num1+=num

print "Impossible"