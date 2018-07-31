#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
	#endif
	
	int n, m;
	cin >> n >> m;

	int food_type[101], freq_food[101] = {0}, max_freq, type;
	for(int i = 0; i < m; i ++){
		cin >> type;
		freq_food[type] ++;
		if(freq_food[type] > max_freq){
			max_freq = freq_food[type];
		}
	}

	bool done = false;
	int possible_max = max_freq;
	int temp_freq_food[101];

	while(!done && possible_max > 0){
		for(int i = 1; i <= 100; i ++){
			temp_freq_food[i] = freq_food[i];
		}
		int count = 0;
		bool flag = true;
		while(count < n && flag == true){
			flag = false;
			for(int i = 1; i <= 100; i ++){
				if(temp_freq_food[i] >= possible_max){
					temp_freq_food[i] -= possible_max;
					count ++;
					flag = true;
					break;
				}
			}
		}
		if(count == n){
			cout << possible_max;
			done = true;
		}
		else{
			possible_max --;
		}
	}
	if(!done){
		cout << "0";
	}

	return 0;
}