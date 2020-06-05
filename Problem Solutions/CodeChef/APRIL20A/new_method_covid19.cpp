#include <bits/stdc++.h>
using namespace std;
bool Placenumbers(vector<int> place){
    if(place.size()<1){
        return true;
    }
    for(int i=0;i<place.size()-1;i++){
        int p=abs(place[i]-place[i+1]);
        if(p<6)
            return false;
    }
        return true;
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> number;
	    vector<int> place;
	    for(int i=0;i<n;i++){
	        int num;
	        cin>>num;
	        number.push_back(num);
	        if(num==1){
	            place.push_back(i);
	        }
	    }
	    int c=Placenumbers(place);
	    if(c==0){
	        cout<<"NO"<<endl;
	    }
	    else{
	        cout<<"YES"<<endl;
	    }
	    
	}
	return 0;
}