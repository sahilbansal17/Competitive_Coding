#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;
#define fl(i, a, b)     for(int i(a); i < (b); i ++)
#define rep(i, n)       fl(i, 0, n)
#define rfl(i, a, b)    for(int i(a); i >= (b); i --)
#define srt(v)          sort((v).begin(), (v).end())
#define pb              push_back
#define mp              make_pair
#define F               first
#define S               second
const ll MOD = 1000000007LL;

class Reroll{
private:
	public:
	int minimumDice(int r, vi dice){	
		srt(dice);
		int n = dice.size();
		int sum = 0, res = 0;
		rep (i, n) {
			sum += dice[i];
		}
		if (sum == r) {
			res = 0;
		}
		else if (sum < r) {
			int cur = sum;
			rep (i, n) {
				cur -= dice[i];
				int mi = cur + (i + 1);
				int ma = cur + 6*(i + 1);
				if (mi <= r && r <= ma) {
					res = (i + 1);
					break;
				}
			}
		}
		else {
			int cur = sum;
			rfl (i, n - 1, 0) {
				cur -= dice[i];
				int mi = cur + (n - i);
				int ma = cur + 6*(n - i);
				if (mi <= r && r <= ma) {
					res = (n - i);
					break;
				}
			}
		}
		return res;
	}
};

int main(){

	Reroll a;
	
	cout << "\n" << a.minimumDice(1, {2}) << "\n";
}