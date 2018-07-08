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
	cin >> m >> n;
	cout << "Dimensions of matrix are : " << m <<", "<<n<<endl;
	int a[m][n];
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
	for(int i=1; i<m; i++){
		for(int j=0; j<n; j++){
			a[i][j] += a[i-1][j];
		}
	}
	for(int i=1; i<m; i++){
		for(int j=1; j<n; j++){
			a[i][j] += a[i][j-1];
		}
	}
	for(int i=1 ; i<n ; i++)
		a[0][i] += a[0][i-1];
	cout<<"Sum matrix:\n";
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	cin >> q;
	cout << "Number of queries : " << q << endl;
	for(int i=1; i<=q; i++){
		int ai, aj, bi, bj;
		cin >> ai >> aj >> bi >> bj;
		cout << "Query #" << i << " : " << "(" << ai << "," << aj << ") to (" << bi << "," << bj << ")" << endl;
		if	(ai > bi || aj > bj)
			cout << "Invalid Query !" << endl;
		else{
			int value = a[bi][bj];
			if (aj > 0)
				value -= a[bi][aj-1];
			if(ai > 0)
				value -= a[ai-1][bj];
			if(ai > 0 && aj > 0)
				value += a[ai-1][aj-1];
			cout << "Output of given query is : " << value << endl;
		}
	}
	return 0;
}

// Time Complexity : O(mn)

// Auxiliary Space Complexity : O(1)
