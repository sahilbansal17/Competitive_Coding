#include <bits/stdc++.h>
using namespace std;
#define M 1000000007

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    long int N;
	    cin>>N;
	    vector<long long int> price;
	    for(long int i=0;i<N;i++){
	        long long int p;
	        cin>>p;
	        price.push_back(p);
	    }
	    sort(price.begin(),price.end(),greater<long long int>());
	    long long int totPrice=0;
	    long int j=0;
	    while(j<N){
	        long long int a=price[j]-j;
	        if (a <= 0){
	        totPrice+=0;}
	       // else if(a<0){
	       // totPrice+=0;}
	        else if(a!= 0){
	        totPrice+=a;}
	        ++j;
	    }
	    cout<<totPrice%M<<endl;
	}
	return 0;
}