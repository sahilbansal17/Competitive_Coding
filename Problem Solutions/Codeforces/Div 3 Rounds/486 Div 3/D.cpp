#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;
typedef pair <int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
#define fl(i,a,b) for(int i(a);i<(b);i++)
#define rep(i,n) fl(i,0,n)
#define rfl(i,a,b) for(int i(a);i>=(b);i--)
#define srt(v) sort((v).begin(),(v).end())
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define slen(s) s.length()
#define F first
#define S second

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif

	int n, num;
	cin >> n;

	vi nums;

	rep(i, n){
		cin >> num;
		nums.pb(num);
	}

	srt(nums); // so that binary_search can be used
	
	int diff = 1, power = 0, maxConsec = 1;
	
	int result[3];

	while(power < 31){
		fl(i, 1, n){
			int current = nums[i];
			// in the previous submission, I just checked for adjacent elements
			
			// first check if current - diff and current + diff both exist
			bool left = binary_search(nums.begin(), nums.end(), current - diff);
			bool right = binary_search(nums.begin(), nums.end(), current + diff);
			if(left && right){
				maxConsec = 3;
				result[0] = current;
				result[1] = current - diff;
				result[2] = current + diff;
				break; // no need to check more
			}

			// now if either of the two exist, then update maxConsec
			if(left){
				maxConsec = 2;
				result[0] = current;
				result[1] = current - diff;
				continue;
			}
			if(right){
				maxConsec = 2;
				result[0] = current;
				result[1] = current + diff;
			}
		}
		if(maxConsec == 3){
			break; // already found the best possible answer
		}
		power += 1;
		diff *= 2;
	}
	switch(maxConsec){
		case 1: 
			cout << "1\n" << nums[0];
			break;
		case 2:
			cout << "2\n" << result[0] << " " << result[1];
			break;
		case 3:
			cout << "3\n" << result[0] << " " << result[1] << " " << result[2]; 
	}
	return 0;
}