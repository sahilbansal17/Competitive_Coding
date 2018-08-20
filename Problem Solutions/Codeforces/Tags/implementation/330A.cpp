#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i < b; i ++)
#define RFOR(i,a,b) for(int i = a; i >= b; i --)
#define ln "\n"
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<"-->"<<y<<"\n"
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<"\n"

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int r, c;
	cin>>r>>c;
	char array[r][c];
	FOR(i,0,r){
		FOR(j,0,c){
			cin>>array[i][j];
		}
	}
	int markerforrows[r] = {0};
	int markerforcoloumns[c] = {0};
	int count = 0;
	int row_count = 0;
	FOR(i,0,r){
		int flag = 0;
		FOR(j,0,c){
			if(array[i][j] == 'S')
				flag = 1;
		}
		if(flag == 0){
			markerforrows[i] = 1;
		}
	}
	FOR(i,0,c){
		int flag = 0;
		FOR(j,0,r){
			if(array[j][i] == 'S'){
				flag = 1;
			}
		}
		if(flag == 0)
			markerforcoloumns[i] = 1;
	}
	FOR(i,0,r){
		if(markerforrows[i] == 1){
			count += c;
			row_count ++;
		}
	}
	FOR(j,0,c){
		if(markerforcoloumns[j] == 1){
			count += (r - row_count);
		}
	}
	cout<<count;
	return 0;
}