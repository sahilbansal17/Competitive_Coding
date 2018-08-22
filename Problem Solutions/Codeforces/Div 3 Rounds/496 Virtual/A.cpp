#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
	#endif

	int n;
	scanf("%d", &n);

	int steps[1010];
	int climbed_in_step[1010];
	int step = 0, current_step = 0;

	for(int i = 0; i < n; i ++){
		cin >> steps[i];
		if(steps[i] == 1 && i != 0){
			climbed_in_step[step] = current_step;
			step ++;
			current_step = 1;
		}
		else{
			current_step ++;
		}
	}
	climbed_in_step[step] = current_step;
	step ++;

	printf("%d\n", step);
	for(int step_no = 0; step_no < step; step_no ++){
		printf("%d ", climbed_in_step[step_no]);
	}

	return 0;
}