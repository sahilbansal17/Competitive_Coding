#include <bits/stdc++.h>
using namespace std;

long long energy(long long num_presses_second_button, long long total_energy, long long energy_reduced_per_click){
	long long n, b, x;
	n = total_energy;
	b = energy_reduced_per_click;
	x = num_presses_second_button;
	return x*(n - x*b);
}

int main(){
	int t;
	cin >> t;

	int n, b;
	while(t --){
		cin >> n >> b;
		int second_button_clicks = n/b/2;
		cout << max(energy(second_button_clicks, n, b), energy(second_button_clicks + 1, n, b)) << "\n";
	}
	return 0;
}