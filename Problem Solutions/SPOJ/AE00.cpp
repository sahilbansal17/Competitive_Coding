#include <iostream>
using namespace std;

int main() {
	int n;cin>>n;
	int count=0;
	for(int i=1;i<=n;i++){
	    for(int j=i;j<=n/i;j++){
	        count++;
	    }
	}
	cout<<count;
	return 0;
}
