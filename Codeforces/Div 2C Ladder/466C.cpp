/* 	Problem Link : http://codeforces.com/problemset/problem/466/C
	Problem Name : Number of Ways
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <climits>

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

int main(){

	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int n;
	cin >> n;
	int a[500001],cnt[500001],ways[500001];
	ll sum = 0,s = 0,req_sum;	
	fl(i,0,n){
		cin >> a[i];
		sum += a[i];
	}
	if(sum % 3 != 0){
		cout << 0; // not possible
	}
	else{
		req_sum = sum/3; // required sum of each part of array
		rfl(i,n-1,0){
			s += a[i];
			if(s == req_sum)
				cnt[i] = 1; // cnt[j] is 1 if sum from jth to nth element = req_sum
			else
				cnt[i] = 0;
		}

		//ways[i] will represent the ways in which sum of elements starting from some index after i(including i) is equal to req_sum 
		ways[n-1] = cnt[n-1];
		rfl(i,n-2,0){
			ways[i] = ways[i+1] + cnt[i];
		}

		ll res = 0; // the final result 
		s = 0; // to store prefix sum
		fl(i,0,n-2){
			s += a[i];
			if(s == req_sum){
				res += ways[i+2];
				// if sum from first i elements is req_sum
				// then the ways in which sum after (i+2)th element is req_sum
				// will be added to our result
				// since then array is partitioned in 3 parts with same sum
			}
		}
		cout << res;
	}

	return 0;
}