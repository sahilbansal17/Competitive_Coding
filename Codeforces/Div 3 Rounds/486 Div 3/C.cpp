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
#define vpii vector < pii >

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif

	int k;
	int n, x, ntotal = 0;
	vi seq;
	vi sums[200010];
	vpii sumseq;
	cin >> k;
	rep(i, k){
		cin >> n;
		ntotal += n;
		int sum = 0;
		rep(j, n){
			cin >> x;
			seq.pb(x);
			sum += x;
		}
		rep(j, n){
			sums[i].pb(sum - seq[j]);
			sumseq.pb(mp(sums[i][j], i + 1));
		}
		seq.clear();
	}
	srt(sumseq);

	int sumreq = sumseq[0].F, seqno = sumseq[0].S;
	bool found = 0;

	int s1, s2, y;
	fl(i, 1, ntotal){
		// cout << sumseq[i].F << " " << sumseq[i].S << "\n";
		if(sumreq == sumseq[i].F && seqno != sumseq[i].S){
			s1 = seqno;
			s2 = sumseq[i].S;
			rep(j, sums[s1 - 1].size()){
				if(sums[s1 - 1][j] == sumreq){
					x = j + 1;
					break;
				}
			}
			rep(j, sums[s2 - 1].size()){
				if(sums[s2 - 1][j] == sumreq){
					y = j + 1;
					break;
				}
			}
			found = 1;
			break;
		}
		else{
			sumreq = sumseq[i].F;
			seqno = sumseq[i].S;
		}
	}
	if(found){
		cout << "YES\n";
		cout << s1 << " " << x << "\n";
		cout << s2 << " " << y << "\n";
	}
	else{
		cout << "NO";
	}
	return 0;
}