#include <bits/stdc++.h>
using namespace std;

class ZigZag{

public:

	int longestZigZag(vector <int> sequence){
		int n = sequence.size();

		int dp[n]; // stores the maximum length subsequence ending at the i-th index
		bool inc[n]; // tells whether sub-sequence is currently increasing or decreasing

		dp[0] = 1; // 1 element subsequence is trivial

		for(int i = 1; i < n; i ++){
			int max_length = 2; // consider sequence[0] and sequence[i]
			dp[i] = max_length; // current best value for dp[i]

			if(sequence[0] < sequence[i]){
				inc[i] = true; // sub-sequence ending at i-th index has last element increase from second last
			}
			else if(sequence[0] > sequence[i]){
				inc[i] = false; // sub-sequence ending at i-th index has last element decreased from second last
			}
			
			for(int j = 1; j < i; j ++){
				// if subsequence ending at j-th index is inc and i-th index element is small and we get better dp value for i-th index
				if(inc[j] && sequence[j] > sequence[i] && dp[j] + 1 > dp[i]){
					dp[i] = dp[j] + 1;
					inc[i] = false;
				}
				else if(!inc[j] && sequence[j] < sequence[i] && dp[j] + 1 > dp[i]){
					dp[i] = dp[j] + 1;
					inc[i] = true;
				}
			}
		}

		return dp[n - 1];
	}
};

int main(){

	ZigZag z;

	int t1[10] = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
	vector <int> test1(t1, t1 + 10);

	int t2[6] = {1, 7, 4, 9, 2, 5};
	vector <int> test2(t2, t2 + 6);

	int t3[1] = {44};
	vector <int> test3(t3, t3 + 1);

	int t4[19] = {70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32};
	vector <int> test4(t4, t4 + 19);

	cout << "\n" << z.longestZigZag(test1);
	cout << "\n" << z.longestZigZag(test2);
	cout << "\n" << z.longestZigZag(test3);
	cout << "\n" << z.longestZigZag(test4);
	cout << "\n";
	return 0;
}