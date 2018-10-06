#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e5 + 10;
const int INF = 1e9;

int n, k;
pii seg[MAXN];
int d[2][MAXN];
vector<int> vec[2][MAXN];
multiset<int> st;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < k; i++)	cin >> seg[i].F >> seg[i].S;
	memset(d, 63, sizeof(d));
	d[1][0] = 0;
	int cur = 0;
	for (int l = 0; l < 2*n;) {
		if (cur < k && l == seg[cur].F){
			int r = seg[cur++].S;
			for (int w = 0; w < 2; w++)
				for (int i = 0; i < MAXN; i++) vec[w][i].clear();

			for (int i = 0; i <= n; i++) {
				vec[0][i].push_back(d[1][i] + 1 + 1);
				vec[0][min(n + 1, i + (r-l)+1)].push_back(-(d[1][i] + 1 + 1));

				vec[1][i].push_back(d[1][i] + 2 + 1);
				vec[1][min(n+1, i+(r-l)+1)].push_back(- (d[1][i] + 2 + 1));

				if (i + (r-l) <= n) {
					vec[1][i+ (r-l)].push_back(d[1][i] + 1);
					vec[1][i+ (r-l) + 1].push_back(-(d[1][i] + 1));
				}
			}

			for (int i = 0; i <= n; i++) {
				vec[1][i].push_back(d[0][i] + 1 + 1);
				vec[1][min(n+1, i+(r-l)+1)].push_back(- (d[0][i] + 1 + 1));

				vec[0][i].push_back(d[0][i] + 2 + 1);
				vec[0][min(n+1, i+1+(r-l))].push_back(- (d[0][i] + 2 + 1));
				
				vec[0][i].push_back(d[0][i] + 1);
				vec[0][i+1].push_back(-(d[0][i] + 1));
			}

			for (int w = 0; w < 2; w++){
				st.clear();
				for (int i = 0; i <= n; i++){
					for (int x:vec[w][i])
						if (x > 0)
							st.insert(x - 1);
						else
							st.erase(st.find(-x - 1));
					d[w][i] = (st.size()? *st.begin(): INF);
				}
			}
			
			l = r;
		}
		else{
			int r = (cur < k? seg[cur].F: 2*n);
			for (int i = n; ~i; i--){
				if (i >= r-l)
					d[1][i] = d[1][i-(r-l)];
				else
					d[1][i] = INF;
			}
			l = r;
		}
	}
	int ans = min(d[0][n], d[1][n]);
	if (ans > (int)1e6)
		cout << "Hungry\n";
	else {
		cout << "Full\n";
		cout << ans << "\n";
	}
	return 0;
}
