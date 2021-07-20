def sieve(n: int):
    prime_numbers = [True] * (n+1)
    prime_numbers[0] = prime_numbers[1] = False

    i = 2
    while i<=n:
        if prime_numbers[i]:
            print(i)

            j=i*i
            while j<=n:
                prime_numbers[j]=False
                j+=i
        i+=1
if __name__ == "__main__":
    n = int(input())
    sieve(n)
