#include <bits/stdc++.h>
using namespace std;

int main(){

	int total_cases, pin_number;
	scanf("%d", &total_cases);

	int num_zeroes;
	for(int case_no = 0; case_no < total_cases; case_no ++){
		scanf("%d", &pin_number);
		// simply divide the pin number by 2 to get the number of zeroes in the denominator
		num_zeroes = pin_number / 2;
		// numerator is always 1, denominator starts with 1
		printf("1 1");
		// print the required number of zeroes
		for(int zero_count = 0; zero_count < num_zeroes; zero_count ++){
			cout << "0";
		}
		printf("\n");
	}

	return 0;
}