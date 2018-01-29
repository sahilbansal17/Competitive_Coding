/* 	Problem Link 	: 	http://codeforces.com/problemset/problem/363/C
	Problem Name 	: 	Fixing Typos
 	author 			: 	sahilbansal17
	date			:	22nd Jan, 2018	
*/
#include <bits/stdc++.h>

using namespace std;

#define fl(i,a,b) for(int i(a);i<(b);i++)
#define rep(i,n) fl(i,0,n)
#define slen(s) s.length()

int main(){

	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	string s,res;

	cin >> s;

	int len = slen(s);

	int typo = 0,copy = 0;
	rep(i,len-1){
		int count = 1;
		while(s[i] == s[i+1]){
			count ++;
			i ++;
		}
		// only once occurring 
		if(count == 1){
			typo = 0;
			copy = 1;
		}
		else{
			// if letter appears more than once
			typo ++ ;
			if(typo == 2){
				// identical letters followed by another couple of identical letters case
				// this typo is resolved by copying the second couple's one letter only
				copy = 1;
				typo = 0;
			}
			else{
				// even if count >=3, the letter will only be copied twice
				copy = 2;
			}
		}
		rep(k,copy){
			res += s[i];
		}

	}	

	int res_len = slen(res);

	// just because we ran the loop till (len-2)th index
	// to make sure that last character, if its count is 1, is added to result
	if(s[len-1]!=res[res_len-1]){
		res += s[len-1];
	}

	cout << res;

	return 0;
}