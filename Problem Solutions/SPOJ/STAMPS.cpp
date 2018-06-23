#include<bits/stdc++.h>
using namespace std;
int arraysum(int[],int);
int main(void){
	int t;cin>>t;//test cases
	int testcase=1;
	while(t--){
	    int stamps;cin>>stamps;
	    int friends;cin>>friends;
	    int array[friends];
	    for(int i=0;i<friends;i++)
	        cin>>array[i];
	    sort(array,array+friends);// sorting them in ascending order
	    int count=0;int sum=0;
	    int i=friends-1;
	    
	    cout<<"Scenario #"<<testcase<<":"<<endl;//output format
	    testcase++;
	    if(arraysum(array,friends)>=stamps){//if the array contains more stamps than required
	        while(sum<stamps){
	            sum += array[i--];
	            count++;
	        }
	        cout<<count<<endl;
	    }
	    else{
	        cout<<"impossible"<<endl;//since there insufficient stamps
	    }
	    if(t>=1)
	        cout<<endl;
	}
	return 0;
}
int arraysum(int* array,int n){//calculating the sum of all elements in an array
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=array[i];
    }
    return sum;
}
