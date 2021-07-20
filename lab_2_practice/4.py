def sum_pairs(my_list: list, number: int):
    count = 0
    for i in my_list:
        for j in my_list:
            if (i+j) == number:
                count += 1
    return count


if __name__ == "__main__":
    n, q = list(map(int, input().split()))
    mylist = list(map(int, input().split()))
    searchlist = []
    print(sum_pairs(mylist, q))
