#include <bits/stdc++.h>

using namespace std;

/* Template file for Online Algorithmic Competitions */
/* Typedefs */
	/* Basic types */
	typedef long long ll;
	typedef unsigned long long ull;
	/* STL containers */
	typedef vector <int> vi;
	typedef vector <ll> vll;
	typedef pair <int,int> pii;
	typedef pair <ll,ll> pll;
	typedef vector < pii > vpii;
	typedef vector < pll > vpll;
/* Macros */
	/* Loops */
	#define fl(i,a,b) for(int i(a);i<(b);i++)
	#define rep(i,n) fl(i,0,n)
	#define rfl(i,a,b) for(int i(a);i>=(b);i--)
	/* Algorithmic functions */
	#define srt(v) sort((v).begin(),(v).end())
	/* STL container methods */
	#define pb push_back
	#define mp make_pair
	/* String methods */
	#define slen(s) s.length()
	/* Shorthand notations */
	#define F first
	#define S second
	#define MOD 1000000007
	#define MAX 100010

bool cmp(string s1, string s2){
	int l1 = slen(s1);
	int l2 = slen(s2);
	if(l1 == l2){
		return s1 > s2;
	}
	return l1 > l2;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif

	int n;
	cin >> n;

	ll l, r;

	ll start[n];
	ll end[n];
	ll points[n + 1];

	fl(i, 1, n + 1){
		points[i] = 0;
	}

	rep(i, n){
		cin >> l >> r;
		start[i] = l;
		end[i] = r + 1;
	}

	sort(start, start + n);
	sort(end, end + n);

	ll csi = 0, cei = 0;
	ll current_pos = start[0] - 1, prev_pos = start[0] - 1;
	ll cv = 0, pv = 0;

	// int ct = 0;
	while(cei < n){

		// cout << "csi: " << csi << ", cei:" << cei << "\n"; 
		pv = cv;
		ll pos;
		if(csi < n && start[csi] < end[cei]){
			// cout << "cond1:\n";
			pos = start[csi];
			while(csi < n && start[csi] == pos){
				cv ++;
				csi ++;
			}
			if(csi == n){
				csi = n - 1;
				start[csi] = 1000000000000000002;
			}
		}
		else if(csi < n && start[csi] == end[cei]){
			// cout << "cond2:\n";
			pos = end[cei];
			while(csi < n && start[csi] == pos){
				csi ++;
				cv ++;
			}
			while(cei < n && end[cei] == pos){
				cei ++;
				cv --;
			}
			if(csi == n){
				csi = n - 1;
				start[csi] = 1000000000000000002;
			}
		}
		else{
			// cout << "cond3:\n";
			pos = end[cei];
			while(cei < n && end[cei] == pos){
				cv --;
				cei ++;
			}
		}
		prev_pos = current_pos;
		current_pos = pos;
		// cout << pv << "\n";
		// cout << "prev: " << prev_pos << "\n";
		// cout << "curr: " << current_pos << "\n";
		points[pv] += (current_pos - prev_pos);
		// ct ++;
		// if(ct > 7){
			// break;
		// }
	}

	fl(i, 1, n + 1){
		cout << points[i] << " ";
	}
	return 0;
}