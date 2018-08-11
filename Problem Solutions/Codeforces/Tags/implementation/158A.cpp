#include<bits/stdc++.h>
using namespace std;


int main(void){
	int n, k;
	cin>>n>>k;
	int array[n];
	for(int i = 0;i < n; i ++){
		cin>>array[i];
	}
	int count = 0;
	for(int i = 0;i < n; i ++){
		if((array[i] >= array[k-1]) && (array[i] > 0)){
			count++;
		}
	}
	cout<<count;
	return 0;
}