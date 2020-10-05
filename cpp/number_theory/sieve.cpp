//the complexity of sieve of eratosthenes is O(nlog(logn))
#include<iostream>
#include<math.h>

using namespace std;
int main(){
int n;
cin>>n;
int primes[n+1];
for (int i=0;i<=n;i++){
    primes[i]=1;
}
primes[0]=0;
primes[1]=0;
for (int i=2;i<=sqrt(n);i++){
    if (primes[i]==1){
        for (int j=2;i*j<=n;j++){
            primes[i*j]=0;
        }
    }
}
for (int i=0;i<=n;i++){
    if (primes[i]==1){
        cout<<i<<endl;
    }
}

}
