//Name : Shivam Singhal
//Email ID : shivamsinghal0610@gmail.com

//program to delete an element from an array 

#include <iostream>
using namespace std;

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
	cout << "Position from which element is to be deleted : " << x << endl;
	for(long long int i = (x-1); i < (n-1); i++)
		arr[i] = arr[i+1];
	cout << "Modified array : ";
	printArray(arr,n-1);
	return 0;
}



//Time Complexity -
//Worst Case : O(n). 

//Auxiliary Space Complexity : O(1). 