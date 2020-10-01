
// A O(n) C++ program to find maximum product pair in an array
#include<bits/stdc++.h>
using namespace std;
 
// Function to find maximum product pair in arr[0..n-1]
void maxProduct(int arr[], int n)
{
    if (n < 2)
    {
        cout << "No pairs exists\n";
        return;
    }
 
    if (n == 2)
    {
        cout << arr[0] << " " << arr[1] << endl;
        return;
    }
 
    // Iniitialize maximum and second maximum
    int posa = INT_MIN, posb = INT_MIN;
 
    // Iniitialize minimum and second minimum
    int nega = INT_MIN, negb = INT_MIN;
 
    // Traverse given array
    for (int i = 0; i < n; i++)
    {
        // Update maximum and second maximum if needed
        if (arr[i] > posa)
        {
            posb = posa;
            posa = arr[i];
        }
        else if (arr[i] > posb)
            posb = arr[i];
 
        // Update minimum and second minimum if needed
        if (arr[i] < 0 && abs(arr[i]) > abs(nega))
        {
            negb = nega;
            nega = arr[i];
        }
        else if(arr[i] < 0 && abs(arr[i]) > abs(negb))
            negb = arr[i];
    }
 
    if (nega*negb > posa*posb)
        cout << "Max product pair is {" << nega << ", "
             << negb << "}";
    else
        cout << "Max product pair is {" << posa << ", "
             << posb << "}";
}
 
// Driver program to test above function
int main()
{
    int arr[] = {1, 4, 3, 6, 7, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    maxProduct(arr, n);
    return 0;
}