/* 	author 	: 	sahilbansal17
	date	:	21st Jan, 2018	
Modified
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int t,a,b,res;
	ll k,sum = 0;

	cin >> t;

	while(t--){
		cin >> k >> a >> b;

		if(a + b == 5 || a + b == 10){
			res = -1;
		}
		else if(a + b == 15){
			if(k == 2){
				res = 1;
			}
			else
				res = -1;
		}
		else{
			if(k == 2){
				if((a + b) % 3 == 0){
					res = 1;
				}
				else{
					res = -1;
				}
			}
			else{
				if((a+b)% 2 == 1){
					// after 3 digits a pattern involving 2486 starts
					sum = a + b + (a + b)%10;
					k -= 3;
					ll to_incl = k/4;
					sum += 20*to_incl;
					int rem = (k % 4);
					if(rem == 1){
						sum += (2*((a+b)%10))%10;
					}
					else if(rem == 2){
						sum += (2*((a+b)%10))%10 + (2*(2*((a+b)%10))%10)%10;
					}
					else if(rem == 3){
						sum += (2*((a+b)%10))%10 + (2*(2*((a+b)%10))%10)%10 + (2*((2*(2*((a+b)%10))%10)%10))%10;
					}
				}
				else{
					// after 2 digits a pattern involving 2486 starts
					sum = a + b;
					k -= 2;
					ll to_incl = k/4;
					sum += 20*to_incl;
					int rem = (k % 4);
					if(rem == 1){
						sum += (a+b)%10;
					}
					else if(rem == 2){
						sum += (a+b)%10 + (2*((a+b)%10))%10;
					}
					else if(rem == 3){
						sum += (a+b)%10 + (2*((a+b)%10))%10 + (2*(2*((a+b)%10))%10)%10;
					}
				}
				if(sum % 3 == 0){
					res = 1;
				}
				else{
					res = -1;
				}
			}
		}
		// cout << sum << "\n";
		if(res == -1){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
		}
	}

	return 0;
}