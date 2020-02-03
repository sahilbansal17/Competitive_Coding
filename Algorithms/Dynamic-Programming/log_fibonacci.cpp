/**
We are given the following problem: compute the n-th Fibonacci number in logarithmic time.
While the basic approaches are correct and will give us the correct answer (obviously), there is a much faster method to compute the n-th Fibonacci number.
As time complexity, there are 2, as a matter of fact:
    1) we can solve our problem by using the closed formula of the Fibonacci numbers (http://mathonline.wikidot.com/a-closed-form-of-the-fibonacci-sequence) and exponentiation by squaring.
        however, due to the work with irrational numbers, this approach only gives us an approximate and is quite costly on the machine because of the way in which float numbers are stored in memory.
    2) a very fast way of solving the problem is by using matrix multiplication;
        this implies the creation of a "fibonacci matrix"; let's assume that we have F[k] and F[k+1] already calculated, placed in a matrix and we would like to multiply the matrix by some other matrix in order to get F[k+1] and F[k+2].
        one way to construct it is like this:

        A *   (  F[k+1] ) =  (  F[k+2]  )
              (  F[k]   )    (  F[k+1]  )

        and a possible solution for A is:

        (  1   1  ) * (  F[k+1]  ) = (  F[k+2]  )
        (  1   0  )   (  F[k]    )   (  F[k+1]  )
        because F[k+2] = F[k+1] + F[k];

        if starting from F[1] = F[2] = 1, we would need to raise A to the n-2nd power in order to get F[n].


    This second approach can be extended to a wide range of dynamic programming problems which deal with recurrence relations since it can dramatically lower the time complexity (from linear to logarithmic).
    In order to keep things simple, I've chosen to create a matrix class and overload the * and ^ operators (so that operations may look like integer ones)
**/

#include <bits/stdc++.h>
using namespace std;

int zeroM[2][2] = {{0, 0}, {0, 0}},
    idenM[2][2] = {{1, 0}, {1, 0}};

class matrix {
    private: int v[2][2]; /// we only need a 2x2 matrix for the job
    public:
        matrix(int x[][2] = zeroM) {
            for(int i = 0; i < 2; i++)
                for(int j = 0; j < 2; j++)
                    v[i][j] = x[i][j];
        }

        int element(int x, int y) {
            return v[x][y];
        }

        friend matrix operator*(const matrix& A, const matrix& B) {
            matrix R;

            for(int i = 0; i < 2; i++)
                for(int j = 0; j < 2; j++)
                    for(int k = 0; k < 2; k++)
                        R.v[i][j] += A.v[i][k] * B.v[k][j];

            return R;
        }

        friend matrix operator^(matrix X, int p) { /// computing X^p in logarithmic time
            matrix R(idenM); /// intialising R as the identity matrix

            while(p > 0) {
                if(p & 1)
                    R = X * R;
                X = X * X;
                p >>= 1;
            }
            return R;
        }
};

int logFibo(int n) {
    int xM[2][2] = {{1, 1}, {1, 0}},
        fM[2][2] = {{1, 0}, {1, 0}};

    matrix X(xM),
           F(fM);
    X = X^(n-2);
    F = F * X;

    return F.element(0, 0);
}

int main() {
    int n;
    cout << "n = "; cin >> n;

    cout << logFibo(n);
}
