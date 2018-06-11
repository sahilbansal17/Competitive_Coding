#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int T, N, colorValue;
	cin >> T;

	vector <int> colors;
	while(T--){

		cin >> N;
		for(int i = 0 ; i < N; i ++){
			cin >> colorValue;
			colors.push_back(colorValue);
		}

		// sort the vector 
		sort(colors.begin(), colors.end());

		// iterate over the entire vector, and find the no of times each colorValue repeats, 
		// answer will be "sigma(Ai) - N" where Ai is the no of times i comes, i represents any element in the array
		// it is the same as "N - no of distinct elements in the array"

		int sz = colors.size();
		int distinctCount = 1; // starting from the 2nd element in the loop below
		for(int j = 1 ; j < sz ; j ++){
			// increment the distinctCount counter only at transition to a different element
			if(colors[j] != colors[j-1]){
				distinctCount ++;
			}
		}

		int res = N - distinctCount;

		cout << res << "\n";

		colors.clear();
	}
	return 0;

}