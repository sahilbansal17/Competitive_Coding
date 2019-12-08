#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector <int> primes;
    bitset<10010> prime; 
    void sieve(int upperbound) {          
      int total = upperbound + 1;                   
      prime.set();                                                 
      prime[0] = prime[1] = 0;                                     
      for (int i = 2; i <= total; i++){
        if (prime[i]) {
            for (int j = i * i; j <= total; j += i) prime[j] = 0; 
            primes.push_back(i);
        }
      } 
    }

    bool isPrime(int N) {                 
      if (N <= 10000) return prime[N];                   
      for (int i = 0; i < (int)primes.size(); i++)
        if (N % primes[i] == 0) return false;
      return true;                    
    } 
    
    bool isPalindrome(int N){
        vector <int> digits;
        while(N){
            int dig = N % 10;
            digits.push_back(dig);
            N /= 10;
        }
        int len = digits.size();
        bool res = true;
        for(int i = 0, j = len - 1; i < j; i ++, j --){
            if(digits[i] != digits[j]){
                res = false;
                break;
            }
        }
        return res;
    }
    
    int primePalindrome(int N) {
        sieve(10000);
        int num = N;
        bool done = false;
        while(!done){
            if(isPalindrome(N) && isPrime(N)){
                return N;
                done = true;
            }
            N ++;
        }
        return -1;
    }
};

int main(){

    Solution s;
    cout << "\n" << s.primePalindrome(100000000) << "\n";
    return 0;
}