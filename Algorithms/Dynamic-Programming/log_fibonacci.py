#We are given the following problem: compute the n-th Fibonacci number in logarithmic time.
#While the basic approaches are correct and will give us the correct answer (obviously), there is a much faster method to compute the n-th Fibonacci number.
#As time complexity, there are 2, as a matter of fact:
#    1) we can solve our problem by using the closed formula of the Fibonacci numbers (http://mathonline.wikidot.com/a-closed-form-of-the-fibonacci-sequence) and exponentiation by squaring.
#        however, due to the work with irrational numbers, this approach only gives us an approximate and is quite costly on the machine because of the way in which float numbers are stored in memory.
#    2) a very fast way of solving the problem is by using matrix multiplication;
#        this implies the creation of a "fibonacci matrix"; let's assume that we have F[k] and F[k+1] already calculated, placed in a matrix and we would like to multiply the matrix by some other matrix in order to get F[k+1] and F[k+2].
#        one way to construct it is like this:

#        A *   (  F[k+1] ) =  (  F[k+2]  )
#              (  F[k]   )    (  F[k+1]  )

#        and a possible solution for A is:

#        (  1   1  ) * (  F[k+1]  ) = (  F[k+2]  )
#        (  1   0  )   (  F[k]    )   (  F[k+1]  )
#        because F[k+2] = F[k+1] + F[k];

#        if starting from F[1] = F[2] = 1, we would need to raise A to the n-2nd power in order to get F[n].


#    This second approach can be extended to a wide range of dynamic programming problems which deal with recurrence relations since it can dramatically lower the time complexity (from linear to logarithmic).
#    Luckily for us, numpy already provides us with matrix multiplication so we don't have to implement it ourselves.
import numpy as np

def mPow(X, p):
    R = np.array([[1, 0], [1, 0]])

    while p > 0:
        if p & 1:
            R = X.dot(R)
        X = X.dot(X)
        p = p >> 1
    return R

def log_fibo(n):
    X = np.array([[1, 1], [1, 0]])
    F = np.array([[1, 0], [1, 0]])

    X = mPow(X, n-2)

    return X[0][0]

n = int(input("n = "))

print(log_fibo(n))
