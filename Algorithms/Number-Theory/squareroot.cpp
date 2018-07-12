#include<bits/stdc++.h>
using namespace std;

int main(void){
	double n ;
	cout<<"Enter a number"<<endl;
	cin>>n;
	if(n >= 0){
		//decimal means the decimal part of our resukt and fraction means the fractional part
		int decimal;
		double fraction;

		for(decimal = 1; decimal * decimal <= n; decimal ++){
			;
		}
		// since we crossed our answer's decimal
		decimal --;
		// x will store the whole number
		double x;
		//doing the same for fraction as for decimal
		for(fraction = 0.0001; fraction <= 1.0000; fraction += 0.0001){
			x = (double) decimal + fraction;
			if((x * x) >= n){
				fraction -= 0.0001;
				break;
			}
		}
		x = (double) decimal + fraction;
		cout<<x;
	}
	else{
		cout<<"Wrong Input! Try again"<<endl;
	}

	return 0;
}
/*
Time Complexity will be O(n) since there is only a single loop till n.
*/