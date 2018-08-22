#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int taxis = 0;
	int a = 0,b = 0,c = 0,d = 0;
	for(int i = 0; i < n; i ++){
		int num;
		cin>>num;
		if(num == 1)
			a++;
		else if(num == 2)
			b++;
		else if(num == 3)
			c++;
		else if(num == 4)
			d++;
		else ;
	}
	taxis += d;
	d = 0;
	taxis += min(a,c); // pairing ones and threes
	taxis += (c - min(a,c));//if three remains.
	a -= min(a,c);
	if(a) // pairing ones among themselves
		taxis += a/4;
	taxis += b/2;
	a = a%4;
	b = b%2;
	if(b){
		if(a ==1 || a == 2 || a == 0){
			taxis += 1;
		}
		else if(a == 3)
			taxis += 2;
		else
			;
	}
	else 
		if(a == 0) 
			;
		else if(a == 1 || a == 2 || a == 3)
			taxis += 1;
		else
			;
	cout<<taxis;
	return 0;
}