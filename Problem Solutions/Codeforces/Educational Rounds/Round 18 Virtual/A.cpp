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


int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif

	int n;

	cin >> n;

	int coordinates_of_cities[n];

	rep(i, n){
		cin >> coordinates_of_cities[i];
	}		

	sort(coordinates_of_cities, coordinates_of_cities + n);

	
	int min_distance = INT_MAX, count_of_cities_with_min_dist = 1;

	rep(i, n - 1){
		int distance = abs(coordinates_of_cities[i + 1] - coordinates_of_cities[i]);
		if(distance < min_distance){
			min_distance = distance;
			count_of_cities_with_min_dist = 1;
		}
		else if(distance == min_distance){
			count_of_cities_with_min_dist ++;
		}
	}

	cout << min_distance << " " << count_of_cities_with_min_dist;
	return 0;
}