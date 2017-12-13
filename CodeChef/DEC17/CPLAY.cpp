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
#include <iomanip>
 
using namespace std;
 
typedef vector <int> vi;
typedef pair <int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i,a,b) for(int i(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define SORT(v) sort((v).begin(),(v).end())
#define pb push_back
#define MOD 1000000007
 
int main()
{
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	string s;
	int wonA,wonB,remA,remB,flag,count;
	while(getline(cin,s)){
		wonA = wonB = 0, flag = 0, remA = 5, remB = 5, count = 0;
		FOR(i,0,10){
			if(s[i]=='0'){
				if(i%2 == 0){
					wonA += 0;
					remA --;
				}
				else{
					wonB += 0;
					remB --;
				}
			}
			else{
				if(i%2 == 0){
					wonA += 1;
					remA --;
				}
				else{
					wonB += 1;
					remB --;
				}	
			}
			count ++;
			int diff = abs(wonA - wonB);
			if(wonA > wonB){
				if(diff > remB){
					flag = 1;
					break;
				}
			}
			else{
				if(diff > remA){
					flag = 1;
					break;
				}
			}
		}
		if(wonA == wonB){
			for(int i = 10; i<20 ; i+=2){
				count +=2;
				if(s[i]=='1'&&s[i+1]=='0'){
					wonA++;
					flag = 1;
					break;
				}
				if(s[i]=='0'&&s[i+1]=='1'){
					wonB++;
					flag = 1;
					break;
				}
			}
		}
		if(flag == 0){
			cout << "TIE";
		}
		if(flag == 1){
			if(wonA > wonB){
				cout << "TEAM-A "<<count;
			}
			else{
				cout << "TEAM-B "<<count;	
			}
		}
		cout << endl;	
	}
 
	return 0;
}