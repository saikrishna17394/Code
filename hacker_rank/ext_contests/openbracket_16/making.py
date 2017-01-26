import math

m = input()
w = input()
p = input()
n = input()


ans = math.ceil(n/(m*w))

days = 0
cur_cnt = 0
cur_rate = m*w

for i in range(1, 2000001):
	req_		