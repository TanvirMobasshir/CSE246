def rod_cut(n: int, price: list):
    if n == 0: return 0
    if dp[n-1]: return dp[n-1]
    
    i = mx = 0
    while i<n:
        value = price[i] + rod_cut(n-i-1, price)
        if value>mx: mx = dp[n-1] = value
        i+=1
    
    return dp[n-1]


if __name__ == "__main__":

    price = list(map(int, input('Input the prices: ').split(' ')))
    global dp
    dp = [None] * len(price)
    print(f"maximum profit: {rod_cut(len(price), price)}")
