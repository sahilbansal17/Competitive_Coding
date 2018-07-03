//https://github.com/sahilbansal17/Competitive_Coding/

//Name: Anil Khatri (@imkaka)
//Email-Id: anil.soccer.khatri@gmail.com

// Now we understand the Algorithm in other file we need to have it in our Template to use Power()
//Whenever Necessary.

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
ll MOD = 1e9+7;

//Power Function (Recursive version) => O(log n)
//Add this to your Template
//It is in one line because it has to be added in everyday used Template.
//For logic and well idented program please refer Power.cpp , Just include it in your Template!!

ll Power(ll x, ll y){
  ll temp;
  if( y == 0)
    return 1;
  temp = Power(x, y/2)%MOD;
  if (y%2 == 0)
    return (temp%MOD*temp%MOD)%MOD;
  else{
    if(y > 0)
      return (x%MOD*temp%MOD*temp%MOD)%MOD;
    //Last Return when y is negative.
    else return (temp*temp)/x;
  }
}

int main(){

  //User Input
  long long base,power;
  cin >> base >> power;
  cout << Power(base , power);


}

//Complexity - O(log N)
