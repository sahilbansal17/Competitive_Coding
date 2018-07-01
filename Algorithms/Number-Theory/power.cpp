
//https://github.com/sahilbansal17/Competitive_Coding/

//Name: Anil Khatri (@imkaka)
//Email-Id: anil.soccer.khatri@gmail.com

//It calculate the power of base^power in O(log power) time complexity.
//It is the function you need in your template all the time.


#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;
//To handle large numbers for more info -> (https://codeaccepted.wordpress.com/2014/02/15/output-the-answer-modulo-109-7/)
#define MOD 1000000007

//Fast Power - Iterative versiom

long long fastPower(long long base, long long power){

  long long result = 1;

  while(power > 0) {
        
        if(power & 1) { 
            result = (result*base) % MOD;
        }
        base = (base * base) % MOD;

        power >>= 1; 
    }

    return (result);


}

//3x3 Matrix 
vector<vector<long long>> matrixPower(vector<vector<long long>> &matrix , int power){
  
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      matrix[i][j]= fastPower(matrix[i][j], power);
    }
  }

  return (matrix);
}


//main 
int main(){
  printf("Power: %lld\n", fastPower(2, 10000000000000));    //Outputs Power: 836339738

//Matrix Initialization
  vector<vector<long long> > matrix(3, vector<long long> (3));

  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cin >>matrix[i][j];
    }
  }
  int power;

  cin >> power;

  vector< vector<long long>> res = matrixPower(matrix, power);

  for (int i = 0; i <3; ++i)
  {
    for (int j = 0; j <3; ++j)
    {
       printf("%lld ", res[i][j]);
    }
    printf("\n");
  }
}


//Time Complexity - O(log power)  => O(log N) As we go "power /= 2" in each iteration.

//Space Complexity - O(1) Since we only used an additional variable result in function.


