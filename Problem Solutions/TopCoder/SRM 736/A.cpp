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

class A0Paper{
private:
	
	public:
	string canBuild (vi a){
		string res;
		int n = a.size();
		rfl (i, n - 1, 1) {
			a[i - 1] += a[i]/2;
		}
		if (a[0] > 0) {
			res = "Possible";
		}
		else {
			res = "Impossible";
		}
		return res;
	}
};

int main(){

	A0Paper a;
	
	cout << "\n" << a.canBuild({0, 2}) << "\n";
}