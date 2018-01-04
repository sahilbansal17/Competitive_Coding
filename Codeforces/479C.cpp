/* 	Problem Link : http://codeforces.com/problemset/problem/479/C
	Problem Name : Exams
*/

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

int main(){

	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int n,a_i,b_i;
	vector <pii> ab;

	cin >> n; // number of exams 

	fl(i,0,n){
		cin >> a_i >> b_i;
		ab.pb(mp(a_i,b_i)); // what a line of code!!!
	}

	srt(ab); // sorting based on first entry in the pair by default

	
	/*
	fl(i,0,n){
		cout << ab[i].F << " " << ab[i].S <<"\n";
	}
	*/

	int cd = -1; // current day
	fl(i,0,n){
		// greedy strategy - if both days possible to give exam, choose the smaller one 
		if(ab[i].F >= cd && ab[i].S >= cd){
			cd = min(ab[i].F, ab[i].S);
		}
		else{
			// else obviously the larger one has to be chosen
			cd = max(ab[i].F, ab[i].S);
		}
	}
	cout << cd; // the day on which final exam is to be given 

	return 0;
}