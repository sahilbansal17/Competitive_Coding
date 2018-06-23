#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif

	int n;

	cin >> n;

	/*

	The problem is transformed in the following way:
	Given 4x + 7y = n
	We need to find the minimum value of x + y
	We write x = (n - 7y)/4
	As we increase y, the value of x decreases
	
	We keep track of the minimum value of x + y that has the largest no of x's

	Now just print x 4's and y 7's
	
	*/

	int x, minimum_x_plus_y = 1000000, max_x = 0;
	for(int y = 0; y <= 250000; y++){
		if(n - 7*y < 0){
			break;
		}
		if((n - 7*y) % 4 == 0){
			x = (n - 7*y)/4;
			if(x + y < minimum_x_plus_y){
				minimum_x_plus_y = x + y;
				max_x = x;
			}
			else if(x + y == minimum_x_plus_y && x > max_x){
				max_x = x;
			}
		}
	}
	
	if(minimum_x_plus_y == 1000000){
		cout << "-1";
		return 0;
	}

	for(int i = 0; i < max_x; i++){
		cout << "4";
	}
	for(int i = 0; i < minimum_x_plus_y - max_x; i++){
		cout << "7";
	}
	return 0;
}