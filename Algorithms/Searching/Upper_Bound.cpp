//Name : Shivam Singhal
//Email ID : shivamsinghal0610@gmail.com

//program to find minimum position of element greater than given value 
//in sorted fashion

#include <iostream>
using namespace std;

void upper_bound(long long int arr[], long long int n, long long int x){
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

void printArray(long long int arr[], long long int n){
	for(long long int i=0; i<n ;i++)
		printf("%lld ",arr[i]);
	printf("\n");
}

int main(){
	long long int n;
	printf("Please enter number of elements:\n");
	scanf("%lld",&n);
	printf("Please enter elements in sorted fashion:\n");
	long long int arr[n];
	for(long long int i=0; i<n ;i++)
		scanf("%lld",&arr[i]);
	long long int x;
	printf("Please enter element whose upper bound is to be found:\n");
	scanf("%lld",&x);
	printf("Entered elements:\n");
	printArray(arr,n);
	upper_bound(arr,n,x);
	return 0;
}


//Time Complexity -
//Worst Case : O(log n).  

//The time complexity turns out to be O(log n) because there are log n comaprisons made 
//at most between the first and last element.

//Auxiliary Space Complexity : O(1). 