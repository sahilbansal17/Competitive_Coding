#include<iostream>
#include<vector>

using namespace std;
//bottom up approach to construct dp array which stores maximum sum of subarray. dp[i] denotes the maximum sum till index i.
void maxSubArray( vector<int> &A,vector<int> &dp,int index)
{
    int n=A.size();
    dp[0] =A[0];
    int l=0,r=0;
    for (int j = 1; j < n ; j++)
    {
        if(dp[j-1]<0)
        l=j;
        dp[j] = A[j]+max(dp[j-1],0);
    }
    int result = dp[0];
    for (int j = 1; j < n ; j++)
    {
        if(result<dp[j])
       {
           result = dp[j];
           r=j;
       }
    }
    cout<<"Maximum contiguous subarray sum is "<<result<<" between "<<l<<" and "<<r;

}
int main()
{
    int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    vector <int> a(n);
    vector <int> dp(n,INT_MIN);
    cout<<"Enter elements"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    maxSubArray(a,dp,n-1);
    return 0;
}
//Time complexity: O(n) since the algorithm involves only one can of the array
