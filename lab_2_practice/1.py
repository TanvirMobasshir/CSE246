def binary_search(my_list, data):
    start = 0
    end = len(my_list) - 1
    while end >= start:
        idx = int((end - start) / 2) + start
        if data == my_list[idx]:
            return idx
        elif data > my_list[idx]:
            start = idx + 1
        else:
            end = idx - 1
    return -1


if __name__ == "__main__":

    n, q = list(map(int, input().split()))
    mylist = list(map(int, input().split()))
    searchlist = []
    for i in range(q):
        searchlist.append(int(input()))
    for i in range(q):
        print(binary_search(mylist, searchlist[i]))
