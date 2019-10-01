# !! ^ represents exponentiation.
#Suppose we have an array X[1...n]. We would like to execute the following queries on it:
#    1 a b -> X[a] increases by the value of b
#    2 a b -> compute & print the sum of X[a..b] (X[a] + X[a+1] + ... + X[b]), let's call it S[a..b].
# The most obvious approach is a brute force one and has an O(1) complexity for queries of type 1 and O(n) for queries of type 2.
# An easy-to-implement efficient is to use a Binary Indexed Tree (BIT or Fenwick Tree), let it be BIT[n+1].
# It is represented as an array:
#    BIT[k] = A[k], if k % 2 == 1.
#             A[k] + A[k-1] + .. + A[k-2^p+1], where 2^p is the biggest power for which k % (2^p) == 0. [1]
#The underlying idea is that any integer > 0 can be expressed as a sum of powers of 2.
#S[a..b] can be easily calculated as S[1..b] - S[1..a-1].
#For example, for the following query: 2 1 46, we will return:
#BIT[46] + BIT[44] + BIT[40] + BIT[32].
#Indeed, BIT[46] = X[46] + X[45],
#        BIT[44] = X[44] + X[43] + X[42] + X[41]
#! We don't actually need X in order to implement the idea above.

#usage -> update(bit_array, size, position, value).
#- in the function below, k & (-k) computes the p in the description.
#- this works because in the internal memory, negative integers are stored as 2's complement.
#Quick example:
#    we have the number 20 = 00010100 (2).
#                      -20 = 11101100 (2)
#    20 & (-20) yields 100 (2), which is 4. Indeed, this satisfies [1].
def update(bit, n, k, v):
    while k <= n:
        bit[k] += v
        k += k & (-k)

#usage -> query(bit_array, size, position).
#- it's somehow the 'reverse' of the update function, adding up the numbers it founds along the way.
def query(bit, n, k):
    s = 0
    while(k > 0):
        s += bit[k]
        k -= k & (-k)
    return s

N = int(input("Give the length of array X (N): "))

BIT = [0] * (N+1)

print("Give the elements of X: ")
for i in range(1, N+1):
    v = int(input())
    update(BIT, N, i, v)

Q = int(input("Give the number of queries: "))

for i in range(Q):
    q, k, v = [int(x) for x in input("Query: ").split()]

    if q == 0:
        update(BIT, N, k, v)
    else:
        print(query(BIT, N, v) - query(BIT, N, k-1))
