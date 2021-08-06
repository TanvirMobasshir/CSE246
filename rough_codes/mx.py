def f(n):
    if n == 0: return 0
    if n == 1: return 1
    if dp[n-1]: return dp[n-1]
    
    dp[n-1] = max(f(n-1)+2, f(n-2)+5)
    return dp[n-1]


if __name__ == "__main__":
    
    n = int(input("enter the number: "))
    global dp
    dp = [None]*n
    print(f(n))
