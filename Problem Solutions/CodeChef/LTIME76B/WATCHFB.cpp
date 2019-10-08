#include <bits/stdc++.h>
// Author: @NavonilDas
// Question: https://www.codechef.com/LTIME76B/problems/WATCHFB

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,o;
		cin>>n;
        long a,b,p1=-1,p2=-1;
    	bool deduct = false;// it is a boolean to set if it is possible to deduct output
		for(int i=0;i<n;++i){
    		cin>>o>>a>>b;
    		deduct = false;// Set Default to false
            // if option is 1 we already know the score
    		if(o == 1)
    			deduct = true,p1 = a,p2 = b;
    		else {
    		    // if both scores are equal we know our favourite team score
                if(a == b)
        			deduct = true,p1 = a,p2 = b;
                
                // Check if one of the score is less than the previous score of the team
        		if(a < p1 || b<p2)
        		    deduct = true,p1 = b,p2 = a;
        		if(a < p2 || b < p1)
        		    deduct = true,p1 = a,p2 = b;
    		}
    		
    		if(deduct) cout<<"YES\n";
    		else cout<<"NO\n";
		}	
		
	}
	
	return 0;
}