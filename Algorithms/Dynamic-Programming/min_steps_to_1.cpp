//Name:Anuj Goyal
//Email:anujg935@gmail.com

//the problem statement of this program is as follows:-
//Given a positive integer n, find the minimum number of steps s, that takes n to 1. You can perform any one of the following 3 steps.
//1.) Subtract 1 from it. (n= n - ­1) ,
//2.) If its divisible by 2, divide by 2.( if n%2==0, then n= n/2 ) ,
//3.) If its divisible by 3, divide by 3. (if n%3 == 0, then n = n / 3 ).

//We will implement this program using 3 different approaches
#include <iostream>
#include <climits>
using namespace std;

//Brute force approach -Time Complexity O(2^n)
int minStepsBruteForce(int n) {
	// Base case
	if(n <= 1) {
		return 0;
	}

	// Recursive calls
	int x = minStepsBruteForce(n - 1);
	
	//initializing the values to max infinity
	int y = INT_MAX, z = INT_MAX;
	if(n % 2 == 0) {
		y = minStepsBruteForce(n/2);
	}

	if(n % 3 == 0) {
		z = minStepsBruteForce(n/3);
	}

	// Calculate final output
	int ans = min(x, min(y, z)) + 1;

	return ans;

}

//helper function of the function minStepsMemoization()
int minStepsHelper(int n, int *ans) {
	// Base case
	if(n <= 1) {
		return 0;
	}

	// Check if output already exists
	if(ans[n] != -1) {
		return ans[n];
	}

	// calling recursion 3 times but storing the results in the array
	int x = minStepsHelper(n - 1, ans);
	
	//initializing the values to max infinity
	int y = INT_MAX, z = INT_MAX;
	if(n % 2 == 0) {
		y = minStepsHelper(n/2, ans);
	}

	if(n % 3 == 0) {
		z = minStepsHelper(n/3, ans);
	}

	int output = min(x, min(y, z)) + 1;

	// Save output for future use
	ans[n] = output;
	
	//returning the output
	return output;

}

//Using Memoization Techniques - Time Complexity O(n)
int minStepsMemoization(int n) {
	//creating a array of n+1 elements
	int *ans = new int[n+1];
	
	//initializing the whole arrray with -1
	for(int i = 0; i <= n; i++) {
		ans[i] = -1;
	}
	
	//calling the helper function that intakes the n and the array
	return minStepsHelper(n, ans);
}

//Using Dynamic Programming Technique - Time Complexity O(n)
int minStepsTo1DP(int n){
	
	//creating a array of n+1 elements
	int *arr = new int[n+1];

	//entering first element 
	arr[1]=0;
	
	//implementing DP approach using the above 2 techniques after analyzing the above  
	for(int i=2;i<=n;i++){
	    arr[i] = arr[i-1]+1;
	    
	    if(i%2==0){
	      	arr[i] = min(arr[i],1+arr[i/2]);
	    }
	    if(i%3==0){
	      	arr[i] = min(arr[i],1+arr[i/3]);
	    }
	}
	//returnint the results
	return arr[n];
}


int main() {
	int n;
	cout<<"Enter the number : ";
	cin>>n;
	cout << "By Brute force : " <<minStepsBruteForce(n)<<endl;
	cout << "By Memoization Techniques : " <<minStepsMemoization(n)<<endl;
	cout << "By Dynamic Programing Technique : " <<minStepsTo1DP(n)<<endl;
}

