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


if __name__ == "__main__":

    length = 5
    price = [0, 2, 8, 9, 10, 12]
    global dp
    dp = [None] * (length+1)
    print(rod_cutting(length, price))

