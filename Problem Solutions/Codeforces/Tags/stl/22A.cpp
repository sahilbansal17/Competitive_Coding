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
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n, val, result;

	cin >> n;

	vi hashTable(201, 0);

	rep(i, n){
		cin >> val;
		hashTable[val + 100] ++ ;
	}	

	// find the second element whose count in hashtable is more than 0
	bool firstVisit = 1, secondVisit = 0, found = 0;
	rep(i, 201){
		if(hashTable[i] != 0 && !firstVisit){
			found = 1;
			result = i - 100;
			break;
		}
		if(hashTable[i] != 0 && !secondVisit){
			secondVisit = 1;
			firstVisit = 0;
		}
	}
	if(found){
		cout << result;
	}
	else{
		cout << "NO";
	}
	return 0;
}