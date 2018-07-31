#include <bits/stdc++.h>

using namespace std;


int factors_of_two[1010][1010]; // (i,j)th index element represents the min factors of two possible to reach (i,j)
int factors_of_five[1010][1010];
int mat[1010][1010];
char to_direction_fact_2[1010][1010]; // represents the direction which was taken to reach (i, j) cell for computing min factors of two
char to_direction_fact_5[1010][1010];

pair <int, int> get_factors_of_two_and_five(int n){
	int count_2 = 0, count_5 = 0;
	while(n % 2 == 0){
		n /= 2;
		count_2 ++;
	}
	while(n % 5 == 0){
		n /= 5;
		count_5 ++;
	}
	return pair <int, int> (count_2, count_5);
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif
	
	int n;
	cin >> n;

	bool zero_exists = false;
	int zero_row, zero_col;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> mat[i][j];
			if(mat[i][j] == 0){
				zero_exists = true;
				zero_row = i;
				zero_col = j;
				mat[i][j] = 10;
			}
		}
	}

	pair <int, int> factors_initial = get_factors_of_two_and_five(mat[0][0]);
	factors_of_two[0][0] = factors_initial.first;
	factors_of_five[0][0] = factors_initial.second;

	for(int i = 1; i < n; i ++){

		pair <int, int> factors_row = get_factors_of_two_and_five(mat[0][i]);
		pair <int, int> factors_col = get_factors_of_two_and_five(mat[i][0]);

		factors_of_two[0][i] = factors_of_two[0][i - 1] + factors_row.first;
		to_direction_fact_2[0][i] = 'R';
		factors_of_two[i][0] = factors_of_two[i - 1][0] + factors_col.first;
		to_direction_fact_2[i][0] = 'D';

		factors_of_five[0][i] = factors_of_five[0][i - 1] + factors_row.second;
		to_direction_fact_5[0][i] = 'R';
		factors_of_five[i][0] = factors_of_five[i - 1][0] + factors_col.second;
		to_direction_fact_5[i][0] = 'D';
	}

	for(int i = 1; i < n; i ++){
		for(int j = 1; j < n; j ++){

			pair <int, int> factors = get_factors_of_two_and_five(mat[i][j]);

			if(factors_of_two[i - 1][j] > factors_of_two[i][j - 1]){
				factors_of_two[i][j] = factors_of_two[i][j - 1] + factors.first;
				to_direction_fact_2[i][j] = 'R';
			}
			else{
				factors_of_two[i][j] = factors_of_two[i - 1][j] + factors.first;
				to_direction_fact_2[i][j] = 'D';	
			}
			
			if(factors_of_five[i - 1][j] > factors_of_five[i][j - 1]){
				factors_of_five[i][j] = factors_of_five[i][j - 1] + factors.second;
				to_direction_fact_5[i][j] = 'R';	
			} 
			else{
				factors_of_five[i][j] = factors_of_five[i - 1][j] + factors.second;
				to_direction_fact_5[i][j] = 'D';
			}
		}
	}
	/*/
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << factors_of_two[i][j] << " ";
		}
		cout << "\n";
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << factors_of_five[i][j] << " ";
		}
		cout << "\n";
	}
	//*/
	int min_possible = min(factors_of_two[n - 1][n - 1], factors_of_five[n - 1][n - 1]);
	
	int min_actual = min_possible;
	if(zero_exists){
		min_actual = min(min_possible, 1);
	}
	cout << min_actual << "\n";

	if(min_actual == min_possible){
		int x = n-1, y = n-1;
		string res;
		if(factors_of_two[x][y] < factors_of_five[x][y]){
			while(!(x == 0 && y == 0)){
				res += to_direction_fact_2[x][y];
				if(to_direction_fact_2[x][y] == 'R'){
					y --;
				}
				else{
					x --;
				}
			}
		}
		else{
			while(!(x == 0 && y == 0)){
				res += to_direction_fact_5[x][y];
				if(to_direction_fact_5[x][y] == 'R'){
					y --;
				}
				else{
					x --;
				}
			}
		}
		reverse(res.begin(), res.end());
		cout << res;
	}
	else{
		for(int i = 0; i < zero_col; i ++){
			cout << "R";
		}
		for(int i = 0; i < zero_row; i ++){
			cout << "D";
		}
		for(int i = zero_col + 1; i < n; i ++){
			cout << "R";
		}
		for(int i = zero_row + 1; i < n; i ++){
			cout << "D";
		}
	}
	return 0;
}