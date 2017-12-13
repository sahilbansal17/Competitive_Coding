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
#define FOR(i,a,b) for(int i(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define SORT(v) sort((v).begin(),(v).end())
#define pb push_back


int main(){

	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int t,n;
	cin >> t;
	int temp[100001],a[100001];
	while(t--){
		cin >> n;
		FOR(i,0,n){
			cin >> a[i];
			temp[i] = a[i];
		}
		if(n == 1){
			cout << "0\n"<< a[0];
		}
		else if(n == 2){
			if(a[0] == a[1]){
				cout << "0\n" << a[0] << " " << a[0] ;
			}
			else{
				cout << "2\n" << a[1] << " " << a[0] ;
			}
		}
		else if(n == 3){
			if(a[0] == a[1]){
				cout << "2\n" << a[2] << " " << a[0] << " " << a[1];
			}
			else if(a[1] == a[2]){
				cout << "2\n" << a[1] << " " << a[0] << " " << a[2];
			}
			else if(a[0] == a[2]){
				cout << "2\n" << a[1] << " " << a[0] << " " << a[2];
			}
			else{
				cout << "3\n" << a[1] << " " << a[2] << " " << a[0];
			}
		}
		else{
			int i = 0, j = n-1;
			while(i < j){
				if(a[i]!=a[j]){
					swap(a[i],a[j]);
				}
				else{
					if(j-i !=2 && j-i != 1){
						swap(a[i],a[i+1]);
						swap(a[j],a[j-1]);
						i++;
						j--;
					}
					else if(j-i == 2){
						swap(a[i],a[i+1]);
						i = j;
						break;
					}
					else{
						swap(a[i],a[i-1]);
						swap(a[j],a[j+1]);
						break;
					}
				}
				i++;
				j--;
			}
			if(i == j){
				FOR(k,0,n){
					if(temp[k]!=a[i] && a[k]!=a[i]){
						swap(a[k],a[i]);
						break;
					}
				}
			}
			cout << n << "\n";
			FOR(i,0,n){
				cout << a[i] << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}