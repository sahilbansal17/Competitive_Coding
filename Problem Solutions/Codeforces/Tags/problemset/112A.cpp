#include<bits/stdc++.h>
using namespace std;

int main(void){
	string a, b;
	cin>>a>>b;
	int flag = 0;
	for(int i = 0; i < a.size(); i ++)
		if(isupper(a[i]))
			a[i] = tolower(a[i]);
	for(int i = 0; i < b.size(); i ++)
		if(isupper(b[i]))
			b[i] = tolower(b[i]);
	for(int i = 0; i < a.size(); i ++){
		if(a[i] == b[i]){
			flag = 1;
			continue;
		}
		else if(a[i] < b[i]){
			flag = 2;
			break;
		}
		else if(b[i] < a[i]){
			flag = 3;
			break;
		}
	}
	if(flag == 1)
		cout<<0;
	else if(flag == 2)
		cout<<-1;
	else if(flag == 3)
		cout<<1;
	else 
		cout<<"error"<<endl;
	return 0;
}