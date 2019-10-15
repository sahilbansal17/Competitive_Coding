/**
We have an arbitrary fraction m/n. Write it as a finite sum of distinct unit fractions. (1/x1 + 1/x2 + ... 1/xk)


A finite sum of distinct unit fractions is called an Egyptian Fractions. Those interested in the subject can read more about it here: https://en.wikipedia.org/wiki/Egyptian_fraction
Algorithmically, we can solve this problem using a greedy approach.

Let x1 be the positive integer such that:
1/x1 <= m/n <= 1/(x1-1)
(x1 is the least integer >= m/n)

If 1/x1 = m/n, then the problem is done.
Otherwise:
    m/n - 1/x1 = (m*x1-n)/(nx1).
    Let m1 = m*x1 - n < m (because m/n < 1/(x1-1))
    Let x2 be another positive integer such that:
        1 / x2 <= m1/(n*x1) <= 1/(x2-1)

    We can do that recursively as long as mk (m found at step k) > 0.

    1/x1, 1/x2, ... 1/xk will be the respective numbers.
example: 5/8 = 1/2 + 1/8
**/

#include <iostream>

using namespace std;

int m, n;
int main()
{
    cout << "Give m and n: "; cin >> m >> n;

    while(m > 0) {
        int x = n/m;
        if(n%m != 0) x++;
        cout << "1/" << x << ' ';
        m = m * x - n;
        n *= x;
    }
    return 0;
}
