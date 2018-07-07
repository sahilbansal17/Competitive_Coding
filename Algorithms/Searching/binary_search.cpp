//Name : Shivam Singhal
//Email ID : shivamsinghal0610@gmail.com

//program to find an element in an array using binary search

#include <iostream>
using namespace std;

void binarySearch(long long int arr[], long long int n, long long int x){
	long long int low = 0, high = n, mid = 0, flag = 0;
	while(low <= high){
		//we break (low+high)/2 into following formula to avoid any overflow of data
		mid = low + (high-low)/2;
		if(arr[mid] == x){
			cout << "Element found at position : " << (mid+1) << endl;
			flag = 1;
			break;
		}
		//if element to be searched exists to the right of middle element, we narrow
		//our search to [mid+1, n)
		if(arr[mid] < x)
			low = mid+1;
		//if element to be searched exists to the left of middle element, we narrow
		//our search to [low, mid)
		if(arr[mid] > x)
			high = mid-1;
	}
	if(flag == 0)
		cout << "Element not found !" << endl; 
}

void printArray(long long int arr[], long long int n){
	for(long long int i=0; i<n ;i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main(){
	long long int n;
	cin >> n;
	cout << "Number of elements : " << n << endl;
	long long int arr[n];
	cout << "Please enter elements in increasingly sorted fashion." << endl;
	for(long long int i=0; i<n ;i++)
		cin >> arr[i];
	cout << "Entered elements : ";
	printArray(arr,n);
	long long int x;
	cin >> x;
	cout << "Element to be searched : " << x << endl;
	binarySearch(arr,n,x);
	return 0;
}



//Time Complexity -
//Worst Case : O(log n). 
//We are basically halving the range over which we are searching the element, so
//it can be mathematically derived that the number of elements being searched at 
//kth iteration is (n/(2^k)), which should be equal to 1 for iteration when element is 
//found. So, for total iterations, n = 2^k, which means k = log n

//Auxiliary Space Complexity : O(1). 