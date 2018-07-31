#include <bits/stdc++.h>
using namespace std;

class SimpleDarts{
private:
	
	public:
	int highestScore(int f){
		int score = 0;
		if(f > 18){
			score = 3*f + 3*(f - 1) + 3*(f - 2);
		}
		if(f == 18){
			score = 54 + 51 + 50;
		}
		if(f < 18 && f > 9){
			score = 50 + 3*f + 3*(f - 1);
		}
		if(f <= 9){
			score = 50 + 25 + 3*f;
		}
		return score;
	}
};

int main(){

	SimpleDarts a;
	
	cout << "\n" << a.highestScore(20) << "\n";
}