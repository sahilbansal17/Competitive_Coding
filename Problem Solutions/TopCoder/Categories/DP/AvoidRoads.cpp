#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class AvoidRoads{
private:
	ll dp[105][105]; // dp[i][j] denotes the no of ways to reach at (i, j)
	public:
	ll numWays(int w, int h, vector <string> bad){

		// initialize the dp table with -1 values for memoization
		for(int i = 0; i < 105; i++){
			for(int j = 0; j < 105; j++){
				dp[i][j] = -1;
			}
		}
		
		return solve(w, h, bad);
	}

	bool blocked(int x1, int y1, int x2, int y2, vector <string> &v){
		string s, n, to_convert;
		int count = 0;
		int nums[4];
		for(int i = 0; i < v.size(); i++){
			s = v[i];
			for(int j = 0; j < s.length(); j++){
				if(s[j] == ' '){
					nums[count] = stoi(to_convert);
					count ++;
					to_convert.clear();
				}
				else{
					to_convert += s[j];
				}
			}
			// 4th number, at the end of string
			nums[count] = stoi(to_convert);
			// cout << "\n" << nums[0] << " " << nums[1] << " " << nums[2] << " " << nums[3] << "\n";
			to_convert.clear();
			count = 0;

			if(x1 == nums[0] && y1 == nums[1] && x2 == nums[2] && y2 == nums[3]){
				return true;
			}
		}
		return false;
	}

	ll solve(int w, int h, vector <string> &bad){
		if(dp[w][h] != -1){
			return dp[w][h];
		}
		if(w == 0 && h == 0){
			return dp[w][h] = 1;
		}
		dp[w][h] = 0;
		if(w - 1 >= 0 && !blocked(w - 1, h, w, h, bad) && !blocked(w, h, w - 1, h, bad)){
			dp[w][h] += solve(w - 1, h, bad);
		}
		if(h - 1 >= 0 && !blocked(w, h - 1, w, h, bad) && !blocked(w, h, w, h - 1, bad)){
			dp[w][h] += solve(w, h - 1, bad);
		}
		return dp[w][h];
	}

};

int main(){

	AvoidRoads a;
	string s1 = "0 0 0 1";
	string s2 = "6 6 5 6";
	vector <string> v;
	v.push_back(s1);
	v.push_back(s2);
	cout << "\n" << a.numWays(6, 6, v) << "\n";
}