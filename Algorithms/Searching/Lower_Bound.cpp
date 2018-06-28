//Name : Shivam Singhal
//Email ID : shivamsinghal0610@gmail.com

//program to find minimum position of element lesser than given value 
//in sorted fashion

#include <bits/stdc++.h>
using namespace std;

void lower_bound(long arr[], long n, long x){
	long count = (n-1), step, low = 0;
	while(count>0){
		step = (count/2);
		low+=step;
		//checking for lower_bound condition
		if(arr[low] < x){
			low++;
			count-=(step+1);
		}
		else
			count=step;
	}
	printf("Lower_bound of %lld is at position: %lld\n",x,low);
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
	long arr[n];
	printf("Please enter elements in sorted fashion:\n");
	for(long i=0; i<n ;i++)
		scanf("%lld",&arr[i]);
	long x;
	scanf("%lld",&x);
	printf("Entered elements:\n");
	printArray(arr,n);
	lower_bound(arr,n,x);
	return 0;
}



//Time Complexity -
//Worst Case : O(log n). 

//The time complexity turns out to be O(log n) because there are log n comaprisons made 
//at most between the first and last element.

//Auxiliary Space Complexity : O(1). 