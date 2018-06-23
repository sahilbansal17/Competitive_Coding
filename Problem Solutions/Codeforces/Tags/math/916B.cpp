#include <bits/stdc++.h>

using namespace std;

/* Template file (modified) for Online Algorithmic Competitions */
/* Typedefs */
	/* Basic types */
	typedef long long ll;
/* Macros */
	/* Loops */
	#define fl(i,a,b) for(int i(a);i<(b);i++)
	#define rep(i,n) fl(i,0,n)
	#define rfl(i,a,b) for(int i(a);i>=(b);i--)

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif

	ll n;
	int k, total_set_bits = 0;

	cin >> n >> k;

	/* map the store which bits are set in the number n */
	map <int, int> count;

	rep(i, 64){
		/* check whether i-th bit is set */
		if( (n >> i) & 1 ){
			count[i] ++ ;
			total_set_bits ++;
		}
	}

	/* if the total set bits are larger than k, then not possible */
	if(total_set_bits > k){
		cout << "No";
		return 0;
	}

	rfl(i, 63, -63){
		/* if transferring the set bits is possible */
		/* doing since we want lowest possible maximum power in the sequence */
		if(total_set_bits + count[i] <= k){
			total_set_bits += count[i];
			/* since 2^x = 2 * 2^(x-1), transfer the set bits to lower bit */
			count[i - 1] += 2 * count[i];
			count[i] = 0;
		}
		else{
			/* no more transfers possible */
			break; 
		}
	}

	/* store the actual sequence in decreasing order */
	multiset <int> sequence; 
	rfl(i, 63, -63){
		rep(j, count[i]){
			sequence.insert(i);
		}
	}

	/* make the sequence length equal to k, 
	   doing the transfers in greedy fashion,
	   starting from the smallest power of two
	   so that the sequence is still 
	   lexographically largest possible 
	*/

	while(sequence.size() < k){
		int current = *sequence.begin();
		sequence.erase(sequence.begin());
		sequence.insert(current - 1);
		sequence.insert(current - 1);
	}

	cout << "Yes\n";
	/* print the sequence in the reverse order, i.e. 
	   decreasing order 
	*/
	multiset <int>::reverse_iterator it = sequence.rbegin();
	while(it != sequence.rend()){
		cout << *it << " ";
		it++ ;
	} 
	return 0;
}