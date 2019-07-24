/*Three Types of Queries 
 1.  Kth smallest element in range 
 2. Elements Less than equal to K
 3. Count of K in range
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod = 1000000007;
const int N = 3e5, M = N;
const int MAX = 1e6;
vector < int > g[N];
ll a[N];
struct wavelet_tree{
	#define pb push_back
	int lo, hi;
	wavelet_tree *l, *r;
	vector < ll > b ;
	//nos are in range [x,y]
	//array indices are [from, to)
	wavelet_tree(ll *from, ll *to, ll x, ll y){
		lo = x, hi = y;
		if(lo == hi or from >= to)
			{
				return;
			}
		int mid = (lo+hi)/2;
		auto f = [mid](int x){
			return x <= mid;
		};
		b.reserve(to-from+1);
		b.push_back(0);
		for(auto it = from; it != to; it++)
			b.pb(b.back() + f(*it));
		//see how lambda function is used here	
		auto pivot = stable_partition(from, to, f);
		l = new wavelet_tree(from, pivot, lo, mid);
		r = new wavelet_tree(pivot, to, mid+1, hi);
	}
 
	//kth smallest element in [l, r]
	int kth(int l, int r,int k){
		if(l > r) return 0;
		if(lo == hi) return lo;
		int inLeft = b[r] - b[l-1];
		int lb = b[l-1]; //amt of nos in first (l-1) nos that go in left 
		int rb = b[r]; //amt of nos in first (r) nos that go in left
		if(k <= inLeft) return this->l->kth(lb+1, rb , k);
		return this->r->kth(l-lb, r-rb, k-inLeft);
	}
 
	//count of nos in [l, r] Less than or equal to k
	int LTE(int l, int r, int k) {
		if(l > r or k < lo) return 0;
		if(hi <= k) return r - l + 1;
		int lb = b[l-1], rb = b[r];
		return this->l->LTE(lb+1, rb, k) + this->r->LTE(l-lb, r-rb, k);
	}
 
	//count of nos in [l, r] equal to k
	int count(int l, int r, int k) {
		if(l > r or k < lo or k > hi) return 0;
		if(lo == hi) return r - l + 1;
		int lb = b[l-1], rb = b[r], mid = (lo+hi)/2;
		if(k <= mid) return this->l->count(lb+1, rb, k);
		return this->r->count(l-lb, r-rb, k);
	}
	~wavelet_tree(){
		delete l;
		delete r;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,n,k,j,q,l,r;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i+1];
	}
	wavelet_tree T(a+1, a+n+1, 1, MAX);
	cin >> q;
	while(q--){
		ll x;
		cin >> x;
		cin >> l >> r >> k;
		if(x == 0){
			//kth smallest
			cout << "Kth smallest: ";
			cout << T.kth(l, r, k) << endl;
		}
		if(x == 1){
			//less than or equal to K
			cout << "LTE: ";
			cout << T.LTE(l, r, k) << endl;
		}
		if(x == 2){
			//count occurence of K in [l, r]
			cout << "Occurence of "<<k<<':';
			cout << T.count(l, r, k) << endl;
		}
	}
	return 0;
} 