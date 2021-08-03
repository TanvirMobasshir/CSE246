<<<<<<< HEAD
def rod(length: int, price: list):
	print(dp)
	if length == 0: return 0
	if dp[length]: return dp[length]
	mx = 0
	i = 1
	while i<=len(price) and length>=len(price):
		val = price[i] + rod(length-i, price)
		if val>mx: mx=val
		i+=1
		dp[length] = mx
	return dp[length]
=======
def rod_cutting(length: int, price: list):
    if len == 0: return 0
    if dp[length]: return dp[length]
    mx = 0
    i = 1
    while i<=(length+1):
        val = price[i]+rod_cutting(length-1, price)
        dp[length] = val
        if val>mx: mx = val
        i+=1

    return mx
>>>>>>> b12038fe5cd5e7828e3b621dacc1b115fba6ae1c


if __name__ == "__main__":

<<<<<<< HEAD
	price = [0, 2, 8, 9, 10, 12]
	length = 10
	global dp
	dp = [None] * (length+1)
	print(rod(length, price))
=======
    length = 5
    price = [0, 2, 8, 9, 10, 12]
    global dp
    dp = [None] * (length+1)
    print(rod_cutting(length, price))

>>>>>>> b12038fe5cd5e7828e3b621dacc1b115fba6ae1c
