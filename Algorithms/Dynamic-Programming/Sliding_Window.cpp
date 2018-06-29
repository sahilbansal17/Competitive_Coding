//Name : Shivam Singhal
//Email ID : shivamsinghal0610@gmail.com

//program to calculate the maximum consecutive sum possible
//in an array such that it is less than or equal to a given 
//number m

#include <iostream>
using namespace std;
 
int main() {
	int n, m;
	cout << "Please enter the total number of elements :\n"; 
	cin >> n ;
	int a[n];
	cout << "Please enter array elements :\n"; 
	for(int i=0; i<n ;i++)
		cin >> a[i];
	cout << "Please enter maximum sum required:\n"; 
	cin >> m;
	int cur_sum=a[0], max_sum=0, start=0;
	for(int i=1; i<n ;i++){
		//checking if current sum is less than or equal to m or not, 
		//and reducing unnecessary elements that occur before index 
		//being checked if sum is greater than m
		while(cur_sum > m && start < i){
			cur_sum = cur_sum - a[start]; 
			start++;
		}
		//storing max sum possible for each interval that is <= m
		max_sum = max(cur_sum,max_sum);
		cur_sum+=a[i];
	}
	//checking for sum found using last element
	if(cur_sum <= m)
		max_sum = max(cur_sum,max_sum);
	else{
		while(cur_sum > m && start < n){
			cur_sum-=a[start];
			start++;
		}
		max_sum = max(cur_sum,max_sum);
	}
	cout<< max_sum <<endl;
	return 0;
} 

// Time Complexity : O(n)

//Though this algorithm looks like a O(n^2) algorithm at first sight, it can be analysed 
//on further observation that this is actually a O(2*n) worst case algorithm as every element
//in the array will be traversed a max of 2 times - one while being added to current sum (cur_sum)
//and the second time when cur_sum exceeds given m and contains that particular element. As we already 
//know, any O(c*n) complexity where c is a constant is depicted as O(n).

// Auxililary Space Complexity : O(1)