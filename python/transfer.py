#char2int
from functools import reduce
# def fn(x,y):
# 	return x*10+y
# def char2int(s):
# 	digits = {'1':1,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,'9':9,'0':0}
# 	return digits[s]
# reduce(fn,map(char2int,'1234567890'))
Digits = {'1':1,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,'9':9,'0':0}
def str2int(s):
	def add(x,y):
		return x*10+y
	def char2int(s):
		return Digits[s]
	return reduce(add,map(char2int,s))