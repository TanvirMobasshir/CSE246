def isSubsqnce(main_string, sequence):
    i = j = 0

    while i<len(main_string) and j<len(sequence):
        if main_string[i] == sequence[j]:
            j+=1
        i+=1
    if j == len(sequence):
        return 1
    else:
        return 0


if __name__ == "__main__":
    main_string = input()
    sequence = input()
    print(isSubsqnce(main_string, sequence))

