#include<bits/stdc++.h>
using namespace std;

int main(void){
	int n, a, b, c;
	cin>>n;
	int count = 0;
	while(n--){
		cin>>a>>b>>c;
		if(a == 1 && b == 1)
			count ++;
		else if( a == 1 && c == 1)
			count ++;
		else if(b == 1 && c == 1)
			count ++;
		else
			continue;
	}
	cout<<count;
	return 0;
}