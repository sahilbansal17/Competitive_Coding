#include <bits/stdc++.h>
// Author: @NavonilDas
// Question: https://www.codechef.com/LTIME76B/problems/ALLSUB


using namespace std;

// This function returns true if string s is a subset of string r
bool conatins(vector<int> &a,vector<int> &b){
	bool ret = true;
	for(int i=0;i<(int)(a.size());++i){
		a[i] -= b[i];
		if(a[i] < 0) {
			ret = false;
		}
	}	
	return ret;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string s,r;
		cin>>s>>r;
		// vector conatining frequency of the charecters in string s r respectively
		vector<int> hsh1(26,0),hsh2(26,0);
		short descending=0; // check if second charecter after the first charecter of s is smaller than or greater than it
		for(char c:s) {
			++hsh1[c-'a'];
			if(descending == 0 && c > s[0]) descending = 1;
			if(descending == 0 && c < s[0]) descending = 2;
		}
		for(char c:r) ++hsh2[c-'a'];

		if(conatins(hsh2,hsh1)){
			string sr = "";
			char fst = s[0]; // first charecter of string s

			// Append all the charecters which are smaller than the first charecter of s
			for(int i=0;i<(fst-'a');++i)
				while(hsh2[i]--)
					sr.push_back('a'+i);
			
			// if the string s contains charecter which is smaller than first charecter then append the string s
			// then further append repetion of first charecter
			// example if s="babd" r = "bbbabaad" -> aa + babd + bb
			if(descending == 2) {
				sr += s;
				s.clear(); // Clear s as it is already appended
			}
			// append repetion of first charecter
			while(hsh2[fst-'a']--)
				sr.push_back(fst);
			// if the string s contains charecter which is greater than first charecter then append the repetion of	
			// first charecter and then append the string s
			// example if s="bdba" r = "bbbabaad" -> aa + bb + bdba
			sr += s;
			// Append all the Remaing charecters
			for(int i=0;i<26;++i)
				while(hsh2[i]-- > 0)
					sr.push_back('a'+i);

			cout<<sr<<"\n";

		}else cout<<"Impossible\n";
	}

	return 0;
}