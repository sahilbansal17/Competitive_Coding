#include<bits/stdc++.h>
using namespace std;

int main(void){
	string a;
	cin>>a;
	// deleting all vowels
	for(int i = 0; i < a.size(); i ++){
		if(a[i] == 'A' || a[i] == 'a' || a[i] == 'O' || a[i] == 'o' || a[i] == 'Y' || a[i] == 'y' || a[i] == 'E' || a[i] == 'e' || a[i] == 'U' || a[i] == 'u' || a[i] == 'I' || a[i] == 'i'){
			a.erase(a.begin() + i);
			i--;
		}
	}
	// inserting "." before consonant
	int n = a.size();
	for(int i = 0; i < a.size(); i += 2){
		a.insert(i,1,'.');
	}
	// lowercase everyone
	for(int i = 0; i < a.size(); i ++){
		if(isupper(a[i])){
			a[i] = tolower(a[i]);
		}
	}
	
	cout<<a;
	return 0;
}