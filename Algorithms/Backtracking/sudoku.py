'''
Suppose we have a 9*9 matrix that has the following properties:
    1. any element of the matrix is a natural number between 1 and 9 inclusively
    2. each line contains all natural numbers between 1 and 9
    3. each column contains all natural numbers between 1 and 9
    4. each of the nine 3*3 submatrixes contains all numbers between 1 and 9.
        i.e.: the submatrix starting at (1, 1) and ending at (3,3),
                                        (1, 3) (line 1 col 3) and ending at (3, 6)
                                        and so forth.

This is called a sudoku grid.

We are given a partially completed sudoku grid and we have to determine a possible solution. (fill it so it respects the conditions above).

This problem is practically solvable by using a basic backtracking approach. The only challenge is efficiently checking if a solution can be valid.
A constant time solution for the validity check can indeed be designed fairly easily.
Suppose we want to make a move and place K on L and C on a grid M[1..9][1..9]. We can use the following approach to check for validity:
    1. for each line 1 through 9, if the line is not L, let it be i, check if M[i][C] != M[L][C]
    2. for each column 1 through 9, if the column is not C, let it be j, check if M[L][j] != M[L][C]
    3. to check for property 4. we should find the starting and ending line and column for the submatrix.
        the approach is similar for lines and columns:
            - we assign a number 0 through 2 to each group of lines/cols (lines 1, 2 and 3 are in line group 0 as they are in the uppermost part of the matrix
                                                                          columns 4, 5 and 6 are in column group 1 as they are in the midlde of the matrix)
            - the starting line/col of a group can be determined quite easily: we just multiply the number of the group by 3 and add 1 (as they are indexed from 0).
            - due to this indexing, we can find the group a specific line/col is by subtracting 1 and dividing it (in the integer number set) by 3 ( (1-1)//3 = 0, (7-1)//3 = 2)

Indeed, if we apply this approach it will take a negligible amount of time to check the validity of a solution. Constant time, as a matter of fact - a mere 20 operations.
In the following implementation I chose to have a predefined matrix as the input could have got quite tricky. The lines and columns are numbered from 1 and the rest of the matrix is empty/filled with 0s
'''

class candidate:
    def __init__(self, x, y):
        self.line = x
        self.col = y


B = [[], [0, 2, 5, 8, 7, 3, 0, 9, 4, 1], [0, 6, 0, 9, 8, 2, 4, 3, 0, 7], [0, 4, 0, 7, 0, 1, 5, 2, 6, 0], [0, 3, 9, 5, 2, 7, 0, 4, 0, 6], [0, 0, 6, 2, 4, 0, 8, 1, 0, 5], [0, 8, 4, 0, 6, 5, 0, 7, 2, 9], [0, 1, 8, 4, 3, 6, 9, 5, 7, 2], [0, 0, 7, 0, 1, 4, 2, 0, 9, 3], [0, 9, 2, 3, 5, 8, 7, 6, 1, 4]]

def valid(val, k):
    c = cand[k]
    for i in range(1, 10):
        if B[i][c.col] == val or B[c.line][i] == val:
            return 0

    l_start = (c.line-1)//3*3+1
    c_start = (c.col-1)//3*3+1
    for i in range(l_start, l_start+3):
        for j in range(c_start, c_start+3):
            if B[i][j] == val:
                return 0
    return 1

found = 0

def backt(k):
    global found, B
    if k == len(cand):
        for i in range(1, 10):
            for j in range(1, 10):
                print(B[i][j], end=' ')
            print('\n')
        found = 1
    elif found == 0:
        for i in range(1, 10):
            if(valid(i, k)):
                B[cand[k].line][cand[k].col] = i
                backt(k+1)
                B[cand[k].line][cand[k].col] = 0

cand = []

for i in range(1, 10):
    for j in range(1, 10):
        if B[i][j] == 0:
            cand.append(candidate(i, j))
backt(0)
