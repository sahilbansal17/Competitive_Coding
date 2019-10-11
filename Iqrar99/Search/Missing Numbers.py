# Iqrar Agalosi Nureyza (@Iqrar99)

# This program is to find all missing numbers in first array.
# then print all of them in increasing order

def main():
    a = int(input())

    # read the input and use map to convert all elements
    # to be integer
    arr = list(map(int, input().split()))    
    set_A = list(set(arr))

    b = int(input())

    brr = list(map(int, input().split()))
    
    miss = []

    # if the frequency is not same, then we get the missing number
    for number in list(set_A):
        if arr.count(number) < brr.count(number):
            miss.append(number)

    for number in brr:
        if number not in set_A:
            miss.append(number)

    # merge the duplicate numbers
    miss = set(miss)

    # use asterisk (*) to unpack all items in list
    print(*sorted(list(miss)))

if __name__ == "__main__":
    main()
