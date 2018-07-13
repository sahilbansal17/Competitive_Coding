#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Downloads/interception.txt", "r", stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
	#endif

	int test_cases, N, coeff;
	scanf("%d", &test_cases);

	for(int case_no = 1; case_no <= test_cases; case_no ++){
		printf("Case #%d: ", case_no);
		scanf("%d", &N);
		for(int i = 0; i <= N; i ++){
			scanf("%d", &coeff);
		}
		if(N & 1){
			printf("1\n0.0");
		}
		else{
			printf("0");
		}
		printf("\n");
	}

	return 0;
}