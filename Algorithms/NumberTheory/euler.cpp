/*In number theory, the totient φ of a positive integer n is defined to be the number of 
positive integers less than or equal to n, that are coprime to n.
For calculating Euler's totient function we use the following relation 
φ(n) = n* (1-(1/p1))*(1-(1/p2)).....(1-(1/pn))
where p1,p2,...,pn are prime numbers which can divide n
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*Time complexity: O(sqrt(N)) for the phi function since loop runs only till sqrt(n)
*/ 
ll phi(ll n) {
    ll result = n;
    for(ll i = 2; i * i <= n; ++i)
        if(n % i == 0) 
        {
            while(n % i == 0)
                {
                    n /= i;
                }
            result -= result / i;
        }
    if(n > 1)
        {
            result -= result / n;
        }
    return result;
}
int main()
{
	ll t,x;
	cin >>t;
	while(t--)
	{
		cin >> x;
		cout << phi(x) << endl;
	}
	return 0;
}
