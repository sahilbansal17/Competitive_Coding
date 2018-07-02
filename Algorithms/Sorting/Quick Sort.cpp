#include<cstdlib> //srand and rand functions.
#include<iostream> // cout and cin operators.
#include<time.h> // time

using namespace std;

int Partition(int [], int, int);
int RandomizedPartition(int [],int, int);
int QuickSort(int [], int, int);

/*
The Key Idea for Quick Sort is partition and thus dividing the big array into
smaller arrays by dividing them across the pivot position and then again finding
pivot position in each of the sub-arrays and again partitioning each of them until
we reach only one element sub-arrays.
*/

int main(void){
	int n;
	cout<<"Quick-Sort Implementation"<<endl;
	cout<<"Enter the number of elements:"<<endl;
	cin>>n;
	
	int array[n];
	cout<<"Enter the array elements:"<<endl;
	for(int i = 0;i < n;i ++ ){
		cin>>array[i];
	}
	
	QuickSort(array, 0, n-1);
	cout<<"Elements after Sorting:\n";
	
	for(int i = 0;i < n;i ++ ){
		cout<<array[i]<<" ";
	}

	cout<<endl;
	return 0;
}

int Partition(int A[], int start, int end){
	int pivot = A[start];//Pivot element set to the first element
	int i,j;//Declaring the counters
	// Here i will be finding the elements greater than the pivot.
	// Here j will be finding the elements lower than the pivot.
	i = start;
	j = end;
	while(i < j){
		// incremanting i till the array value is greater than pivot
		while(A[i] <= pivot && i <= end){
			i++;
		}
		while(A[j] > pivot && j >= start){
			j--;
		}
		// swapping the values so as to shift the lower values to the left and
		// greater values to the right.
		if(i<j)
			swap(A[i], A[j]);
	}
	// now i has became equal to or greater than i since it has left the while loop
	// so we will be swapping the pivot value and the value at jth position since j
	// denotes the perfect sorted positioon for pivot.
	swap(A[start], A[j]);
	return j;
}

int RandomizedPartition(int A[], int start, int end){
	int Random;
	srand(time(NULL));
	// generates a random number between start and end.
	Random = start + (rand() % (end - start) ); 
	// swapping the random indexed element with the last element.
	swap(A[Random], A[start]);
	return Partition(A, start, end);
}

int QuickSort(int A[], int start, int end){
	// if start = end, there is no point in sorting since a single element is always sorted.
	if(start < end){
		// Getting the Perfect position for the starting element of elements
		// between current "start" and end "variable"
		int PivotProperPosition = RandomizedPartition(A, start, end);
		// Now the pivot is in its perfect position.

		// Quicksorting elements to the left of pivot element.
		QuickSort(A, start, PivotProperPosition - 1);
		// Quicksorting elements to the right of pivot element.
		QuickSort(A, PivotProperPosition + 1, end);
	}
}

// TIME COMPLEXITY -
/*
BEST CASE:
Best case will be when we will be having the partition always at middle of the array since it will
reduce the number of times we will have to make comparisons and we will be making comparisons 
n times. Each time the array will be divided by 2 untill we get a single element.
so, (n/2/2/2/2/2/.... so on) = 1.
so, (n/ (2^k) ) = 1.
so, n = 2^k.
so, k = log(n)

Thus the total time complexity in best case will be O(n log(n)).
*/

/*
WORST CASE:
Worst case will be when the partition will happen always at the end/start.
because in this case we will have to make maximum comparisons.
At the first turn we will make "n" comparisons.
At the second turn we will make "n-1" comparisons.
At the third turn we will make "n-2" comparisons.
...  so on

At the nth turn we will make 1 comparison.

So Total will be addition of these i.e, (n)(n-1)/2;
Thus the Order of time complexity will be (n^2)!
Time Complexity: O(n^2)
*/

/*
AVERAGE CASE:
Quick-Sort takes O(nlog(n)) time in expectation.
This is found after considering all the n! permutations of all the n elements in the array.
*/