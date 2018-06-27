
//https://github.com/sahilbansal17/Competitive_Coding/

//Name: Anil Khatri (@imkaka)
//Email-Id: anil.soccer.khatri@gmail.com

//It calculate the power of base^power in O(log power) time complexity.
//It is the function you need in your templete all the time.


#include<iostream>
#include<cstdio>

using namespace std;
//To handle large numbers for more info -> (https://codeaccepted.wordpress.com/2014/02/15/output-the-answer-modulo-109-7/)
#define MOD 1000000007

//Fast Power - Iterative versiom

long long fastPower(long long base, long long power){

  long long result = 1;

  while(power > 0) {
        // Can also use (power & 1) to make code even faster
        if(power % 2 == 1) { 
            result = (result*base) % MOD;
        }
        base = (base * base) % MOD;

        // Can also use power >>= 1; to make code even faster
        power = power / 2; 
    }

    return (result);


}


//main 
int main(){
  printf("Power: %l", fastPower(2, 10000000000000));    //Outputs Power: 836339738
}


//Time Complexity - O(long power)  => O(log N) As we go "power /= 2" in each iteration.

//Space Complexity - O(1) Since we only used an additional variable result in function.


