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
#define F first
#define S second
#define MOD 1000000007

ll _sieve_size;
bitset<10000010> bs;   

vector < pair<ll,ll> > pq;
int N;
void sieve(ll upperbound) {          
  _sieve_size = upperbound + 1;                   
  bs.set();                                                 
  bs[0] = bs[1] = 0;                                     
  for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
    
    for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
    pq.pb(mp(i*i,i*i));  
} }                                           

void min_heapify(int i){
	int left = 2*i + 1; // since indexing is from 0
	int right = 2*i + 2;
	int smallest;
	if(left < N && pq[left] < pq[i]){
		smallest = left;
	}
	else 
		smallest = i;
	if(right < N && pq[right] < pq[smallest]){
		smallest = right;
	}
	if(smallest != i){
		swap(pq[i], pq[smallest]);
		min_heapify(smallest);
	}
}
int main(){

	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	sieve(10000000);  
	N = pq.size() ; // total primes squares in the vector 
	int n;
	cin >> n;

	int found = 0, count = 0;
	
	pair<ll, ll> top;
	top = pq[0];
	
	pq[0].F += pq[0].S ; // update 4 to 8, since 2nd required no is 8
	count ++ ;
	if(n == 1){
		found = 1;
	}

	ll prev = top.F;

	while(!found){
		top = pq[0];
		if(top.F != prev){
			count ++ ;
			prev = top.F;
		}
		if(count == n){
			// cout << "\n\n";
			found = 1;
			break;
		}
		// cout << top.F << "\n";
		
		// first update the top element
		pq[0].F = pq[0].F + pq[0].S;
		// now call heapify so that smaller element comes on top again
		min_heapify(0);
	}
	// while(pq.empty() == false){
	// 	cout << pq.top().F << "\n";
	// 	pq.pop();
	// }
	
	cout << top.F;
	return 0;
}