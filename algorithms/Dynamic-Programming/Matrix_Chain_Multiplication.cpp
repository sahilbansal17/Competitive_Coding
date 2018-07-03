#include<iostream>
#include<cstring>
using namespace std;
//DP solution requires bottom up filling of matrix with increasing chain length.
int matrixChainMultiplication(int order[],int n)
{
    int i,j,k;
    int temp[n][n];
    memset(temp, 0, sizeof(temp[0][0]) * n * n);
    //Multiplication cost is 0 for single matrix i.e length=1
    for(i=1;i<n;i++)
        temp[i][i]=0;
    for(int length=2;length<n;length++)
    {
        for(i=1;i<n-(length-1);i++)
        {
            j=i+length-1;
            temp[i][j]=INT_MAX;
            for(k=i;k<j;k++)
            {
                int currcost=temp[i][k]+temp[k+1][j]+order[i-1]*order[k]*order[j];
                if(currcost<temp[i][j]) // minimum cost is stored
                    temp[i][j]=currcost;
            }
        }
    }
    return temp[1][n-1];
}
int main()
{
    int arr[]={10,20,30,40,30};
    cout<<"Minimum multiplication cost is "<<matrixChainMultiplication(arr,5);
    return 0;
}
//Time complexity:O(n^3)
//Space Complexity:O(n^2)