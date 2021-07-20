def largest_range(q: int, arr: list):
    count = 0
    i = 0

    while i < len(arr):
        sum = arr[i]
        if sum == q:
            count += 1
            i += 1
        elif sum > q:
            i += 1
        elif sum < q:
            j = i + 1
            while j < len(arr):
                sum = sum + arr[j]
                if sum >= q:
                    count += 1
                    if sum == q:
                        i = j+1
                    else:
                        i = j
                    break
                j += 1
                if j == len(arr):
                    count += 1
                    return count
    return count


if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))
    q = int(input())
    result = largest_range(q, arr)
    print(result)
