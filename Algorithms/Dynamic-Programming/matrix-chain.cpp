/**
For those who are not familiar with matrix multiplication, I suggest reading this wikipedia article: https://en.wikipedia.org/wiki/Matrix_multiplication
Suppose we have a matrix multiplication chain m = m1 * m2 * ... * mn.
As input, we have an array of sizes, d.
The size of mi = (d[i-1], d[i]).
Minimise the total number of integer multiplications in order to evaluate the expression.

Because matrix multiplication is associative, all parenthesis placements lead to the same result.
One naive method is to use backtracking and determine the placement with the minimum number of multiplications.
However, this approach is quite ineffective as it has exponential complexity.

Luckily, we can use Dynamic Programming in order to solve this problem.
Suppose we have a cut between the i-th and i+1-st matrix in the chain. Then, both the prefix of the cut and its suffix should be evaluated optimally.

Therefore, we will build a 2D array M[1..n] [1..n].
best[i][j] = minimum number of integer multiplications in order to evaluate mi * m(i+1) * ... * mj

The recursive formulas will be:
    M[i][i] = 0
    M[i][i+1] = d[i-1] * d[i] * d[i+1]
    M[i][j] = min( {M[i][k] + M[k+1][j], d[i-1] * d[k] * d[j], for i <= k < j and j != i+1. and 1 <= i <= j

    The solution will be in M[0][N-1].

Test data:
N = 4
d = 13 5 89 3 34
expected: 2856
**/
#include <iostream>
#include <limits>

using namespace std;

const int LMAX = 50;

int N,
    M[LMAX+1][LMAX+1], D[LMAX+1];

void DP() {
    for(int d = 1; d < N; d++)
        for(int i = N - d - 1; i >= 0; i--) {
            int j(i+d);
            M[i][j] = INT_MAX;
            for(int k = i; k < j; k++)
                M[i][j] = min(M[i][j],
                              M[i][k] + M[k+1][j] + D[i] * D[k+1] * D[j+1]);
        }
}

int main()
{
    cout << "Give matrix number (N): "; cin >> N;
    cout << "Give the size array (d): ";
    for(int i = 0; i <= N; i++)
        cin >> D[i];
    DP();

    cout << M[0][N-1];
    return 0;
}
