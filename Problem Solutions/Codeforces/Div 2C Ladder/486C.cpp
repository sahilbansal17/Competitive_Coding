/* 	Problem Link : http://codeforces.com/problemset/problem/486/C
	Problem Name : Palindrome Transformation
 	author 	: 	sahilbansal17
	date	:	22nd Jan, 2018	
*/

#include <bits/stdc++.h>

using namespace std;

#define fl(i,a,b) for(int i(a);i<(b);i++)
#define rfl(i,a,b) for(int i(a);i>=(b);i--)

int calc(char a, char b){
	int temp1 = a - b, temp2;
	if(temp1 < 0){
		temp2 = temp1 + 26;
	}
	else{
		temp2 = -1*temp1 + 26;
	}
	return min(abs(temp1), temp2);
}

int main(){

	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int n,p;
	cin >> n >> p;

	string s;
	cin >> s;

	int len = s.length(), rmax, lmin, updown = 0, res = 0;

	// case 1 : p is on the left side of the string
	if(p  <= len/2){
		rmax = p-1;
		fl(i,p-1,len/2){
			if(s[i] != s[len - 1 - i]){
				rmax = i;
				updown += calc(s[i], s[len - 1 - i]);
			}
		}
		lmin = p-1;
		rfl(i,p-2,0){
			if(s[i] != s[len - 1 - i]){
				lmin = i;
				updown += calc(s[i], s[len - 1 - i]);
			}	
		}
	}
	else{
	// case 2 : p is on the right side of the string
		rmax = p-1;
		fl(i,p-1,len){
			if(s[i] != s[len - 1 - i]){
				rmax = i;
				updown += calc(s[i], s[len - 1 - i]);;
			}
		}
		lmin = p-1;
		rfl(i,p-2,len/2){
			if(s[i] != s[len - 1 - i]){
				lmin = i;
				updown += calc(s[i], s[len - 1 - i]);
			}	
		}
	}
	// part common to both the cases
	res += updown;
	int left = (p-1)-(lmin);
	int right = (rmax)-(p-1);
	if(left > right){
		res += 2*right + left;
	}
	else{
		res += 2*left + right;
	}
	cout << res;
	
	return 0;
}