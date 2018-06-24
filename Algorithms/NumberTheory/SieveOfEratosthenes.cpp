// @ lavishsaluja
#include <iostream>
#include<math.h>
using namespace std;

int main(void){
    int n;
    cin>>n;
    //prime[i] = 1 will imply that i is prime & prime[i]=0 will imply that i is not prime
    int prime[n+1];
    for(int i = 0; i <= n; i ++)
	//considering all as primes as of now.
        prime[i] = 1;
    //since 0 & 1 are not prime.
    prime[0] = 0;
    prime[1] = 0;
    /*
    Here we will be running are first loop only till sqrt(n) instead of n because we know that
    if a number is prime it does not have any factor till its square root so we
    can use it for optimization.
    */
    for(int i = 2; i <= sqrt(n);i ++){
	//if i is prime
        if(prime[i] == 1){
            for(int j = 2; j*i <= n; j ++){
		//setting the multiples of i to 0 because they can't be prime.
                prime[i*j] = 0;
	    }
        }
    }
    for(int i = 0; i <= n; i ++){
        if(prime[i] != 0){
            cout<<i<<endl;
        }
    }
    return 0;
}
/*
Time Complexity O(nlog(log(n))) whereas following brute force will end you up with O(n*sqrt(n))
T(n) = n/2 + n/3 + n/5 + .... + n/p' + .... n/p + .. (where p and p' are prime numbers less than n)
thus it becomes T(n) = n * (sum of reciprocals of all primes till n).
which is equal to n*log(log(n)), a complexity very near to O(n)
you may refer to this article for the proof of same:
https://www.wikiwand.com/en/Divergence_of_the_sum_of_the_reciprocals_of_the_primes
*/
