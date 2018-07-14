// Name : Shivam Singhal
// Email ID : Shivam Singhal

// Algorithm on weighted job scheduling

#include <bits/stdc++.h>
using namespace std;

struct node{
	int start ;
	int finish ; 
	int profit ;
};

// boolean function to return which finish time is lesser
bool cmpFinish(node s1, node s2){
	return (s2.finish > s1.finish);
}

// finding job before current job that doesn't have issue with current job.
int binarySearch(node a[], int index){ 
	// we take high as one less than the index because we got to check
	// for jobs that occur before current job
	int low = 0, high = index - 1, mid = 0 ;         
 	while (low <= high){
 		mid = (low + high) / 2;
 		// checking for issue
        if (a[mid].finish <= a[index].start){
        	if (a[mid + 1].finish > a[index].start)
        		return mid;
            else
				low = mid + 1;
        }
        else
        	high = mid - 1;
     }
     // returns -1 if all jobs before index have an issue
     return -1;                         
}

// function to calculate maximum profit from given jobs
int findMaxProfit(node a[], int n){
    // sorting jobs according to finish time
    sort(a, a + n, cmpFinish);    
    int arr[n];
    arr[0] = a[0].profit;
    for(int i = 1; i < n; i++){
        int x = a[i].profit;
        // looking for jobs that don't have issue with current job
        int value = binarySearch(a, i);
        // found at least one job with no issue
        if (value != -1){
            x += arr[value];
        }
        // checking whether to include or exclude by taking maximum
        arr[i] = max(x, arr[i-1]); 
    }
    return arr[n-1];
}
 
int main(){
	int n, i;
 	cout  << "Please enter number of jobs." << endl;
 	cin >> n;
 	cout << "Number of Jobs : " << n << endl;
 	cout << "Please enter start time, finish time and profit in each job." << endl;
 	node a[n];
 	cout << "Start time, Finish time, Profit :" << endl;
 	for(i = 0; i < n; i++){
 		cin >> a[i].start >> a[i].finish >> a[i].profit ;
 		cout << a[i].start << " " << a[i].finish << " " << a[i].profit << endl;
 	}
 	cout << "Maximum profit : " << findMaxProfit(a, n) << endl;
    return 0;
}

// Worst case Time Complexity : O(nlogn)
// This is because we have used in-built function sort to sort elements whose worst case
// time complexity is nlogn. Also, we have carried out binary search (log n) inside a 
// loop that runs for n times

 // Auxiliary Space Complexity : O(n) 
