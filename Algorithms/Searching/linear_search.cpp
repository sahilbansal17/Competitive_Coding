//Name : Shivam Singhal
//Email ID : shivamsinghal0610@gmail.com

//program to find an element in an array using linear search

#include <iostream>
using namespace std;

void linearSearch(long long int arr[], long long int n, long long int x){
	int flag = 0;
	for(long long int i=0; i<n; i++){
		//looking for element sequentially
		if(arr[i] == x){
			//maintaining flag variable for element to be searched
			flag = 1;
			cout << "Element found at position : " << (i+1) << endl;
		}
	}
	if(flag==0)
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
	for(long long int i=0; i<n ;i++)
		cin >> arr[i];
	cout << "Entered elements : ";
	printArray(arr,n);
	long long int x;
	cin >> x;
	cout << "Element to be searched : " << x << endl;
	linearSearch(arr,n,x);
	return 0;
}



//Time Complexity -
//Worst Case : O(n). 
//The algorithm uses a n runtime loop to iterate over all elements and print whether
//element to be searched exists or not. 

//Auxiliary Space Complexity : O(1). 