// Sieve Of Eratosthenes
// Time Complexity O(nlog(log(n))) whereas following brute force will end you up with O(n*sqrt(n))
#include <iostream>
#include<math.h>
using namespace std;

int main() {
    int n;cin>>n;
    int prime[n+1];//prime[i]=1 will imply that i is prime & prime[i]=0 will imply that i is not prime
    for(int i=0;i<=n;i++)
        prime[i]=1;//considering all as primes as of now.
    prime[0]=0;
    prime[1]=0;//since 0 & 1 are not prime ofcourse
    
    /*
    Here we will be running are first loop only till sqrt(n) instead of n because we know that
    if a number is prime it does not have any factor till its square root so we
    can use it for optimization.
    */
    for(int i=2;i<=sqrt(n);i++){
        if(prime[i]==1){//if i is prime
            for(int j=2;j*i<=n;j++){
                prime[i*j]=0;//setting the multiples of i to 0 because they can't be prime ofcourse
            }
        }
    }
    for(int i=0;i<=n;i++){
        if(prime[i]!=0){
            cout<<i<<endl;
        }
    }
	return 0;
}