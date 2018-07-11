// Name : Shivam Singhal
// Email ID : shivamsinghal0610@gmail.com
 
// Array doubling and amortised complexity
 
#include <iostream>
using namespace std;

// function to double array size using amortised technique
void arrayDoubling(int c, int arr[], int* size)
{
	//doubling array size (using call by reference)
	*size = (*size) * 2;
	// creating temporary array of double size
	int double_arr[*size];
	// copying existing elements in original array to temporary array
	for(int i = 0; i < c; i++)
		double_arr[i] = arr[i];
	// deleting memory allocated by original array
	delete [] arr;
	// re-inserting values into original array with double size
	for(int i = 0; i < c; i++)
		arr[i] = double_arr[i];
}
 
int main(){
	int c = 0;
	int size = 1;
	//allocating original array of size 1
	int* arr = new int[size];
	while(1){
		cout << "Please enter a number.\n";
		int n;
		cin >> n;
		cout << n << endl;
		//if index at which new number is to be entered doesn't exceed limit
		if (c < size)
			arr[c++] = n;
		else{
			//doubling array using amortise technique
			arrayDoubling(c, arr, &size);
			//entering new number
			arr[c++] = n;
		}
		cout << "Do you wish to enter another number ? (Y, y / N, n)\n";
		char p;
		cin >> p;
		if (p == 'N' || p == 'n')
			break;
	}
	cout << "Final size of array : " << size << endl;
	cout << "Number of elements stored in array : " << c << endl;
	cout << "Array elements : " << endl;
	for(int i = 0; i < c; i++)
		cout << arr[i] << " ";
	return 0;
}
// Sample Case :
// Input : 
// 1
// Y
// 2
// N
 
// Output :
// Please enter a number.
// 1
// Do you wish to enter another number ? (Y, y / N, n)
// Y
// Please enter a number.
// 2
// Do you wish to enter another number ? (Y, y / N, n)
// N
// Final size of array : 2
// Number of elements stored in array : 2
// Array elements : 
// 1 2 
 
 
 
// Amortised Time Complexity for insertion : O(1)
// Worst Case Time complexity : O(n^2)
// This is because each insertion takes O(n) time and we are considering n insertions. This is only an upper
// bound and not strictly (n^2). 

// Analysis of amortised time complexity : 
 
// Let us take the case of inserting 5 elements.
// For the 1st element, we need only 1 operation for insertion.
// For the 2nd element, we first copy the first element into temporary array and then insert 
// the new element, because array is full. This costs us 2 operations. 
// For the 3rd element, we first copy the first two elements into temporary array and then insert 
// the new element, because array is full. This costs us 3 operations. 
// For the 4th element, we simply insert new element because array isn't full. This costs us 1 operation.
// For the 5th element, we first copy the first four elements into temporary array and then insert 
// the new element, because array is full. This costs us 5 operations. 
// Total number of operations = 1 + 2 + 3 + 1 + 5
// Here, we break the non-ones (say, x) into (1+(x-1)). So, 
// total operations = (1+1+1+1+1) + (1+2+4), which can be generalised as n + (1+2+4+...)
// This value is always <= (n + n), as the right term takes log (n) operations 
// Hence, amortised cost can be considered to be <= (n + n) / n <= 2
// Therefore, amortised cost = O(1)