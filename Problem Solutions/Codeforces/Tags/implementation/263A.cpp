#include<bits/stdc++.h>
using namespace std;

int mod(int);

int main(void){
	int array[5][5];
	for(int i = 0; i < 5;i ++)
		for (int j = 0; j < 5;j ++)
				cin>>array[i][j];
	int a = 53, b = 24;
	for(int i = 0; i < 5; i ++){
		for(int j = 0; j < 5;j ++){
			if(array[i][j] == 1){
				a = i;
				b = j;
			}
		}
	}
	a += 1;
	b += 1;
	//cout<<"a = "<<a<<" "<<"b = "<<b<<endl;
	cout<<mod(3 - a) + mod(3 - b);
	return 0;
}
int mod(int x){
	if(x < 0)
		return -x;
	return x;
}