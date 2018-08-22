// Name : Shivam Singhal
// Email ID : shivamsinghal0610@gmail.com
// Algorithm to calculate the sum of elements contained in a sub-matrix
// formed by given 2 co-ordinates in a query taking first point as upper left
// corner and the second point as the lower right corner

#include <iostream>
using namespace std;

int main()
{
	int m, n, q;
	cout << "Please enter the dimensions of the matrix." << endl;
	cin >> m >> n;
	cout << "Dimensions of matrix are : " << m <<", "<<n<<endl;
	int a[m][n];
	cout << "Please enter the elements of the matrix." << endl;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++)
			cin >> a[i][j];
	}
	cout << "Matrix elements are :" << endl;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	// taking column wise sum
	for(int i=1; i<m; i++){
		for(int j=0; j<n; j++){
			a[i][j] += a[i-1][j];
		}
	}
	// taking row wise sum 
	for(int i=0; i<m; i++){
		for(int j=1; j<n; j++){
			a[i][j] += a[i][j-1];
		}
	}
	// the sum matrix contains the sum contained in all elements
	// from (0,0) to (i,j) at (i,j)
	cout<<"Sum matrix:\n";
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	cout << "Please enter the number of queries." << endl;
	cin >> q;
	cout << "Number of queries : " << q << endl;
	cout << "Please enter the 2 co-ordinates for which sum is to be found.\n";
	cout << "Make sure that the co-ordinates are 0-indexed.\n";
	cout << "While the first co-ordinate should correspond to the top left co-ordinate, the second co-ordinate should correspond to the bottom right co-ordinate." << endl;
	for(int i=1; i<=q; i++){
		int ai, aj, bi, bj;
		cin >> ai >> aj >> bi >> bj;
		cout << "Query #" << i << " : " << "(" << ai << "," << aj << ") to (" << bi << "," << bj << ")" << endl;
		// in case of improper rectangle
		if	(ai > bi || aj > bj || ai < 0 || bi < 0 || ai >= m || bi >= m || aj < 0 || bj < 0 || aj >= n || bj >= n)
			cout << "Invalid Query !" << endl;
		else{
			// sum of all elements from (0,0) to (bi,bj), i.e., the larger rectangle
			int value = a[bi][bj];
			// it can be seen that we need to remove the value of some elements from the total sum 
			// obtained so far. We first remove the sub-matrix which occurs to the left of the required
			// sub-matrix, i.e. (0,0) to (bi, aj-1)
			if (aj > 0)
				value -= a[bi][aj-1];
			// we now remove the sub-matrix which occurs on top of the required sub-matrix, i.e., (0,0) to
			// (a1-1,bj)
			if(ai > 0)
				value -= a[ai-1][bj];
			// If observed carefully, it can be seen that the elements in sub-matrix (0,0) to (ai-1,aj-1) have 
			// been subtracted twice, so we add that again
			if(ai > 0 && aj > 0)
				value += a[ai-1][aj-1];
			cout << "Output of given query is : " << value << endl;
		}
	}
	return 0;
}

// Time Complexity : O(mn)
// We are using a nested loop of m*n which helps us pre-calculate the sum matrix. Now, each query can 
// easily be executed in O(1) time using mathematics and intuition.

// Auxiliary Space Complexity : O(1)
