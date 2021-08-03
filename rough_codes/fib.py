def fib(n: int, start: int, second: int, count: int): #		time complexity: O(n)
	count+=1
#	print(start)
	if count==n: 
		return start
	return fib(n, second, start+second, count)

def Fib(n: int):									 #     time complexity: O(n^2)
	if n == 1: return 0
	if n == 2: return 1
	return Fib(n-1)+Fib(n-2)

def fib_dynamic(n: int):							#  	   time complexity: O(n)
	print(dp)
	if n == 1: return 0
	if n == 2: return 1
	if dp[n]: return dp[n]
	dp[n] = fib_dynamic(n-1) + fib_dynamic(n-2)
	return dp[n]

def fibonacci(n: int):								#	  doesn't work
	Phi = 1.6180339
	return round(Phi * n)


if __name__ == "__main__":
	n = int(input())
	global dp
	dp = [None] * (n+1)
#	print(f'''
#			fib = {fib(n, 0, 1, 0)},
#			Fib = {Fib(n)},
#			fibonacci = {fibonacci(n)}
#			''')
	print(fib_dynamic(n))
