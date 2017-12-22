#include <iostream>
using namespace std;

#define FOR(i,a,b) for(int i(a);i<(b);i++)

void solve(int m, int s){

	if(s > 9*m){
		cout << "-1 -1";
	}
	else if(s == 9*m){
		FOR(i,0,m){
			cout << 9;
		}
		cout << " ";
		FOR(i,0,m){
			cout << 9;
		}
	}
	else if(s == 0 && m != 1){
		cout << "-1 -1";
	}
	else{
		int ct = s/9;
		if(m == ct+1){
			cout << s - ct*9;
			FOR(i,0,ct){
				cout << 9;
			}
		}
		else{
			cout << 1;
			int rem_min = s - (ct)*9 - 1;
			if(s % 9 == 0){
				rem_min = 8;
				ct --;
			}
			if(rem_min == 0){
				FOR(i,0,m-ct-1){
					cout << 0;
				}
				FOR(i,0,ct){
					cout << 9;
				}
			}
			else{
				FOR(i,0,m-ct-2){
					cout << 0;
				}
				cout << rem_min;
				FOR(i,0,ct){
					cout << 9;
				}
			}
		}
		cout << " ";
		FOR(i,0,ct){
			cout << 9;
		}
		int rem = s - ct*9;
		cout << rem;
		FOR(i,ct+1,m){
			cout << 0;
		}
	}
	cout << "\n";
}

int main(){

	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int m,s;
	cin >> m >> s;

	solve(m,s);
	return 0;
}