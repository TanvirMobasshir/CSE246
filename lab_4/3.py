def divisor_number(n: int):
    div_num_list = [0] * (n+1)

    i = 1
    while i<=n:
        j=i
        while j<=n:
            div_num_list[j]+=1
            j+=i
        i+=1
    return div_num_list

def divisor_sum(n: int):
    div_sum = [0] * (n+1)

    i = 1
    while i<=n:
        j=i
        while j<=n:
            div_sum[j]+=i
            j+=i
        i+=1
    return div_sum


if __name__ == "__main__":
    n = int(input())
    div_list = divisor_number(n)
    div_sum_list = divisor_sum(n)
    
    i = 1
    while i<= n:
        print(div_list[i], div_sum_list[i])
        i+=1

