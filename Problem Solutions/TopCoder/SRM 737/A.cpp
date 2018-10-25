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

class Make737Easy{
public:
	int count (string s) {
		ll res = 0;
		int n = s.length();
		rep (i, n) {
			fl (j, i + 1, n) {
				fl (k, j + 1, n) {
					if (s[i] == '7' && s[j] == '3' && s[k] == '7') {
						res ++;
					}
				}
			}
		}
		return res;
	}
};

int main(){

	Make737Easy a;
	
	cout << "\n" << a.count("737") << "\n";
}