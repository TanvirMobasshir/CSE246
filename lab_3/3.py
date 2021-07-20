def total(arr, n, q):
    sum = 0
    cnt = 0
    max_count = 0

    for i in range(n):
        if (sum + arr[i]) <= q:
            sum += arr[i]
            cnt += 1

        elif sum != 0:
            sum = sum - arr[i - cnt] + arr[i]

        max_count = max(cnt, max_count)

    return max_count


if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))
    k = int(input())
    print(total(arr, n, k))
