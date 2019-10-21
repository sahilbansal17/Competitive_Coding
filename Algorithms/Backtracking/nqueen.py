'''We are given N queens and an N*N chess board. Find all queen placements such as no 2 queens attack each other.
2 queens attack each other if they are placed on the same line, colon or diagonal. Show the first solution and the total number of solutions.

This is a classic backtracking problem. You can find a different approach from what I am going to describe below here: https://github.com/sahilbansal17/Competitive_Coding/blob/master/Algorithms/Backtracking/nqueen.cpp

From the 'no 2 queens on the same line' condition, it is obvious that we can store our solution as a permutation-like array: let x[1..N] be our solution; then, if x[i] = j it means that the queen on line i is on colon j.
Now, we will use backtracking in order to generate all possible solutions and check which of them are valid.
Checking if a solution is valid in O(N*N) time is approached in the approach I've linked above.
We want to determine a way to answer the question 'Can this solution be valid?' in O(1) time.
For that, we have to 'trade time for space' - quite a nice bargain in our situation.

We will take advantage of 2 diagonal properties. Let B be our board and, i be an arbitrary line and j be an arbitrary column. Then:
    - the difference of i and j is unique for each left (main) diagonal
        i.e: if i = j, the cell will be on the first left diagonal (starting from top left)
             if i = 1 and j = 2, the cell will be on the second left diagonal (starting from B[1][2])
             if i = 2 and j = 3, the cell will be on the same diagonal as B[1][2].
    - the sum of i and j is unique for each right (second) diagonal
        i.e.: if i = 1 and j = 7, B[i][j] will be on the 7-th right diagonal (starting from left to right).

Drawing the chess board and checking this properties for yourself is a great exercise to understand this.
With that said, we only have to use two arrays, let them be mainDiag and secDiag. Let l and c be a line and a column:
    - if mainDiag[n+l-c] (so we won't have negatives) is true, then there is already a queen placed on the l-c+1-st main diagonal.
    - if secDiag[c+l-1] is true, then there is already a queen placed on the c+l-1-st second diagonal (from left to right).
Before recursing we only have to set those to true and after coming back from recursion mark them as false.

So, we have got a way to check if a solution can be valid in O(1) time and O(n) space complexity, which is also the optimal way in which we can do this.'''

N = int(input("Give the number of queens (N): "))

x = [0] * (N+1)
col = [False] * (N+1)
main_diag = [False] * (2*N)
sec_diag = [False] * (2*N)
sol = 0

def mark(l, c, v = True):
    global col, main_diag, sec_diag
    col[c] = v
    main_diag[N+c-l] = v
    sec_diag[c+l-1] = v

def show():
    for i in range(1, N+1):
        for j in range(1, N+1):
            print("* " if x[i] == j else "- ", end='')
        print('\n')

def valid(l, c):
    return (not col[c] and not main_diag[N+c-l] and not sec_diag[c+l-1])

def backt(k):
    if k <= N:
        for i in range(1, N+1):
            x[k] = i

            if valid(k, i):
                mark(k, i)
                backt(k+1)
                mark(k, i, False)
    else:
        global sol
        sol += 1
        if sol == 1: show()

backt(1)
print(sol)
