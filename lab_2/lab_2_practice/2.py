def bubble_sort(my_list):
    for i in range(len(my_list)):
        for j in range(len(my_list)):
            if my_list[j] > my_list[i]:
                my_list[i], my_list[j] = my_list[j], my_list[i]


if __name__ == "__main__":

    a = int(input())
    mylist = list(map(int, input().split()))
    bubble_sort(mylist)
    for i in mylist:
        print(str(i) + ' ', end="")
