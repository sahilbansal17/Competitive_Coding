//Name:Anuj Goyal
//Email:anujg935@gmail.com

//This program is to find the fibonacci using 3 different approaches
#include<iostream>

using namespace std;

//Brute force approach -Time Complexity O(n^2)
int fibo_1(int n) {
	//base case for recursion
	if(n <= 1) {
		return n;
	}
	//calling recursion
	int a = fibo_1(n - 1);
	int b = fibo_1(n - 2);
	return a + b;
}

//helper function of the function fibo_2()
int fibo_helper(int n, int *ans) {
	//base case for recursion
	if(n <= 1) {
		return n;
	}

	// Check if output already exists
	if(ans[n] != -1) {
		return ans[n];
	}

	// Calculate output
	int a = fibo_helper(n-1, ans);
	int b = fibo_helper(n-2, ans);

	// Save the output for future use
	ans[n] = a + b;
	
	// Return the final output
	return ans[n];
}

//Using Memoization Techniques - Time Complexity O(n)
int fibo_2(int n) {
	//creating a array of n+1 elements
	int *ans = new int[n+1];
	
	//initializing the whole arrray with -1
	for(int i = 0; i <= n; i++) {
		ans[i] = -1;
	}
	//calling the helper function that intakes the n and the array
	return fibo_helper(n, ans);
}

//Using Dynamic Programming Technique - Time Complexity O(n)
int fibo_3(int n) {
	//creating a array of n+1 elements
	int *ans = new int[n+1];
	
	//entering first 2 elements of the fibonacci series in the array
	ans[0] = 0;
	ans[1] = 1;
	
	//as in fibonacci series nth fibonacci is the sum of previos 2 elements
	for(int i = 2; i <= n; i++) {
		ans[i] = ans[i-1] + ans[i-2];
	}

	return ans[n];
}
int main()
{
	int n;
	cout<<"Enter the number : ";
	cin>>n;
	cout << "By Brute force : " <<fibo_1(n)<<endl;
	cout << "By Memoization Techniques : " <<fibo_2(n)<<endl;
	cout << "By Dynamic Programing Technique : " <<fibo_3(n)<<endl;
}
