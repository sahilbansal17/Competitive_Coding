#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i < b; i ++)
#define RFOR(i,a,b) for(int i = a; i >= b; i --)
#define ln "\n"
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<"-->"<<y<<"\n"
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<"\n"

bool amazing(int j, unsigned int* points){
	unsigned int max = points[0];
	unsigned int min = points[0];
	FOR(i, 0, j){
		if(points[i] > max)
			max = points[i];
		if(points[i] < min)
			min = points[i];
	}
	//debug2(max, min);
	if(points[j] > max)
		return true;
	if(points[j] < min)
		return true;
	else
		return false;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unsigned int n;
	cin>>n;
	unsigned int points[n];
	FOR(i,0,n)
		cin>>points[i];
	int amazing_contests = 0;
	FOR(i,1,n){
		if(amazing(i,points)){
			amazing_contests++;
			//debug1(amazing_contests);
		}
		else
			continue;
	}
	cout<<amazing_contests;
	return 0;
}