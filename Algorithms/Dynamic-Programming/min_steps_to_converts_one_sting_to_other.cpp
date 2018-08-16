//Name:Anuj Goyal
//Email:anujg935@gmail.com

//this program is to find the minimum number of steps required to make one string equal to other
//In order to do so you can perform following three operations only :
//1. Delete a character
//2. Replace a character with another one
//3. Insert a character

//Implementing this proble with 3 approaches

#include <iostream>
#include<string>
using namespace std;

//This is a brute force approach
int editDistance(string s, string t) {
	// Base case when the size of any one of the given string becomes equal to zero
	//than the required number of steps is just the length of non empty string
	if(s.size() == 0 || t.size() == 0) {
		return max(s.size(), t.size());
	}

	//checking if the first char of each string is same or not
	//if same than just caling the recursion on smaller strings 
	if(s[0] == t[0]) {
		return editDistance(s.substr(1), t.substr(1));
	}
	//if first chars of strings are not equal thn there are 3 operations
	//Delete,Replace and Insert 
	//therefore calling recursion 3 time for each operations
	else {
		// Insert
		int x = editDistance(s.substr(1), t) + 1;
		// Delete
		int y = editDistance(s, t.substr(1)) + 1;
		// Replace
		int z = editDistance(s.substr(1), t.substr(1)) + 1;
		
		//returning the minimum of all the operations
		return min(x, min(y, z));
	}
}

//Memoization Approach
//this is a helper function to editDistance_Memoization() with additional
// 2d array
int editDistance_Memoization(string s, string t, int **ans) {
	// Base case when the size of any one of the given string becomes equal to zero
	//than the required number of steps is just the length of non empty string
	if(s.size() == 0 || t.size() == 0) {
		return max(s.size(), t.size());
	}

	int m = s.size();
	int n = t.size();
	
	//checking if the answer already exisit in array if yes than just return it
	if(ans[m][n] != -1) {
		return ans[m][n];
	}
	
	//checking if the first char of each string is same or not
	//if same than just caling the recursion on smaller strings 
	if(s[0] == t[0]) {
		//saving the the result of recursion at m,n indx for further use
		ans[m][n] = editDistance_Memoization(s.substr(1), t.substr(1),ans);
	}
	//if first chars of strings are not equal thn there are 3 operations
	//Delete,Replace and Insert 
	//therefore calling recursion 3 time for each operations
	//and saving the results of recursion at aprropriate index of array
	else {
		//Insert
		ans[m-1][n] = editDistance_Memoization(s.substr(1), t,ans);
		//Delete
		ans[m][n-1] = editDistance_Memoization(s, t.substr(1),ans);
		//Replace
		ans[m-1][n-1] = editDistance_Memoization(s.substr(1), t.substr(1),ans);
		
		//saving the final result as the minimum of all the above operations plus 1
		ans[m][n] = 1 + min(ans[m-1][n], min(ans[m][n-1], ans[m-1][n-1]));
	}
	//Returning the final result
	return ans[m][n];

}

//editDistance_Memoization() function that required number of steps
int editDistance_Memoization(string s, string t) {
	//getting the length of both string in m and n respectively
	int m = s.size();
	int n = t.size();
	//creating a 2d array dynamically
	//and initializing each element with -1
	int **ans = new int*[m+1];
	for(int i = 0; i <= m; i++) {
		ans[i] = new int[n+1];
		for(int j = 0; j <= n; j++) {
			ans[i][j] = -1;
		}
	}
	//calling and returning helper function with array as additional parameter
	return editDistance_Memoization(s, t, ans);

}

//Dynamic Programming Approach
int editDistance_DP(string s, string t) {
	//getting the length of both string in m and n respectively
	int m = s.size();
	int n = t.size();
	//creating a 2d array dynamically
	int **ans = new int*[m+1];
	for(int i = 0; i <= m; i++) {
		ans[i] = new int[n+1];
	}
	
	//filling the first column 
	for(int j = 0; j <= n; j++) {
		ans[0][j] = j;
	}
	
	//filling the first column 
	for(int i = 0; i <= m; i++) {
		ans[i][0] = i;
	}
	
	//filling the other empty indexes of array
	//iterationg over every index
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			//checking if the first char of each string is same or not
			if(s[m-i] == t[n-j]) {
				ans[i][j] = ans[i-1][j-1];
			}
			//if not than the answer is min of its isert ,delete,and replace result plus 1
			else {
				ans[i][j] = min(ans[i-1][j], min(ans[i][j-1], ans[i-1][j-1])) + 1;
		
			}
		}
	}
	//returning the result
	return ans[m][n];

}



int main() {
	string s;
	string t; 
	cout<<"Enter both Strings Respectively : ";
	cin >> s >> t;
	
	cout <<"Min number of steps by Brute Force approach :" <<editDistance(s, t) << endl;
	cout <<"Min number of steps by Memoization approach :" <<editDistance_Memoization(s, t) << endl;
	cout <<"Min number of steps by DP approach :" <<editDistance_DP(s, t) << endl;
}

