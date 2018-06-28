//Name : Shivam Singhal
//Email ID : shivamsinghal0610@gmail.com

/*program to find minimum position of element greater than given value 
in sorted fashion*/

#include <bits/stdc++.h>
using namespace std;

void upper_bound(long arr[], long n, long x){
	long count = (n-1), step, low = 0;
	while(count>0){
		step = (count/2);
		low+=step;
		//checking for upper_bound condition
		if(x>=arr[low]){
			low++;
			count-=step+1;
		}
		else
			count=step;
	}
	printf("Upper_bound of %lld is at position: %lld\n",x,low);
}

void printArray(long arr[], long n){
	for(long i=0; i<n ;i++)
		printf("%lld ",arr[i]);
	printf("\n");
}

int main(){
	long n;
	printf("Please enter number of elements:\n");
	scanf("%lld",&n);
	printf("Please enter elements in sorted fashion:\n");
	long arr[n];
	for(long i=0; i<n ;i++)
		scanf("%lld",&arr[i]);
	long x;
	scanf("%lld",&x);
	printf("Entered elements:\n");
	printArray(arr,n);
	upper_bound(arr,n,x);
	return 0;
}

/*

Time Complexity -
Worst Case : O(nlog n).  

Auxiliary Space Complexity : O(1). Use of just extra variables.

*/