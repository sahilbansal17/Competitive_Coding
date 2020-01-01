//Matrix Multiplication in C++ by Jasani Dhruv

#include<iostream> 
using namespace std;
 
int main()
{
	int a[5][5],b[5][5],c[5][5],m,n,p,q,i,j,k;
	cout<<"Matrix Multiplication Implementation"<<endl;
	cout<<"Enter rows and columns of first matrix:";
	cin>>m>>n;
	cout<<"Enter rows and columns of second matrix:";
	cin>>p>>q;
 
//in below statement we are checking for first matrix columns to second matrix row if condition satisfy then it will go inside the statement.
	if(n==p)				
	{
//now here we are entering the values for first matrix.
		cout<<"\nEnter first matrix:\n";
		for(i=0;i<m;++i)
		{
			for(j=0;j<n;++j)
				cin>>a[i][j];
		}

 //now here we are entering the values for second matrix.
		cout<<"\nEnter second matrix:\n";
		for(i=0;i<p;++i)
		{
			for(j=0;j<q;++j)
				cin>>b[i][j];
 
		}

//now we are making a new matrix here to store the result of multiplication matrix of first & second.			
		cout<<"\nThe new matrix is:\n";
		for(i=0;i<m;++i)
		{
			for(j=0;j<q;++j)
			{
				c[i][j]=0;	//initialising new matrix by inserting zero value to it ie zero matrix.
				for(k=0;k<n;++k)
				{
					c[i][j]=c[i][j]+(a[i][k]*b[k][j]);	//this the the formula of multiplication matrix.
				}
				cout<<c[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
	else
		cout<<"\nSorry!!!! Matrix multiplication can't be done";
 
	return 0;
}