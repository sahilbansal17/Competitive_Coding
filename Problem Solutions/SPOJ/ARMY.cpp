#include<algorithm>
#include <iostream>
using namespace std;

int main() {
	int t;cin>>t;
	while(t--){
	    int ng,nm;cin>>ng>>nm;
	    int array1[ng],array2[nm];
	    for(int i=0;i<ng;i++)
	        cin>>array1[i];
	    for(int i=0;i<nm;i++)
	        cin>>array2[i];
	    sort(array1,array1+ng);
	    sort(array2,array2+nm);
	    if(array1[ng-1]>=array2[nm-1]){
	        cout<<"Godzilla"<<endl;
	    }
	    else{
	        cout<<"MechaGodzilla"<<endl;
	    }
	}
	return 0;
}