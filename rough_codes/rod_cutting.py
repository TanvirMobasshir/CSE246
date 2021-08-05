def rod_cutting(length: int, price: list, cut_list: list):
    if length < 0: return 0
    if dp[length]: return dp[length]
    mx = 0
    i = 0
    while i <= length:
        val = price[i] + rod_cutting(length - (i + 1), price, cut_list)
        if val > mx:
            dp[length] = mx = val
            cut_list.append(length)
        i+=1

    return mx


if __name__ == "__main__":

    length = 8
    price = [1, 5, 8, 9, 10, 17, 17, 20]
    global dp, cut_list
    cut_list = []
    dp = [None] * len(price)
    print(rod_cutting(len(price) - 1, price, cut_list))

