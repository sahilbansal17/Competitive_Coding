# Iqrar Agalosi Nureyza (@Iqrar99)

# This program is to findi a pair of numbers. If the sum is equal to m,
# then print the output

import sys

# Function to search the pair of numbers
def icecreamParlor(n,m, arr):

    # we will use dictionary to easier the search
    d = dict()
    
    # The complexity will be O(N)
    for i in range(n):
        if(arr[i] in d and d[arr[i]] != 0):
            print(d[arr[i]] , i + 1)
            break
        if(arr[i] < m):
            d[m - arr[i]] = i + 1
        
        

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        m = int(input())
        n = int(input())
        arr = input().split(' ')
        arr = list(map(int, arr))
        
        # Calling the function
        icecreamParlor(n,m, arr)
