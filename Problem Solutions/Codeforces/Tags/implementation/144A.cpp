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
	int n;
	cin>>n;
	int array[n];
	FOR(i, 0, n){
		cin>>array[i];
	}
	int max = array[0], min = array[0];
	FOR(i,0,n){
		if(max < array[i])
			max = array[i];
		if(min > array[i])
			min = array[i];
	}
	//debug2(max, min);
	// we have the max and min now
	int max_index = 0, min_index = 0;
	FOR(i, 0, n){
		if(array[i] == max){
			max_index = i;
			break;
		}
	}
	FOR(i, 0, n){
		if(array[i] == min){
			min_index = i;
			//break;
		}
	}
	//debug2(max_index, min_index);
	int time = 0;
	if(max_index < min_index){
		cout<<(max_index + (n - 1 - min_index));
	}
	else if(max_index > min_index){
		cout<<(max_index + (n - 2 - min_index));
	}
	else{
		cout<<0;
	}
	return 0;
}