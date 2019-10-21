#include<bits/stdc++.h>
using namespace std;

/** The main logic to identify in this is to not to check the star value of numbers whose
    star value you have already checked, as the star value of this element would be less
    than its factor, because the factor divides the this number and all those number in the
    array which is divisible by that number.
    We also transverse the array backwards to as we want arr[j]%arr[i] for j<i  **/

int main(){
    // Faster IO
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // take input
    int t;
    cin>>t;
    while(t--)  // Run a loop for testcases
    {
        int n;   // take input of array size.
        cin>>n;
        int* arr = new int[n]; // Declare a new array
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];  // Take array input
        }
        int mx = *(max_element(arr,arr+n));  // find maximum element using max_element

        // Declare an array of size mx+1 to mark the numbers already visited.
        bool* isvisited = new bool[mx+1]();
        int ans=0;      // Initially declare ans as zero

        // For loop to find star value (note loop is backwards)
        for(int i=n-1;i>=0;i--)
        {
            int cnt=0;  //Initialize count
            // loop goes in this condition if only its factors in array are unvisited.
            if(!isvisited[arr[i]])  
            {
                for(int j=i-1;j>=0;j--) 
                {
                    // if number is divisible by arr[i]
                    if(arr[j]%arr[i]==0)
                    {
                        cnt++; // then update count
                        isvisited[arr[j]]=true;  // and mark that number as visited
                    }
                }
                isvisited[arr[i]]=true; // mark the original number also as visited
                ans = max(ans,cnt); // update ans as max of star value
            }
        }
        cout<<ans<<endl;  // print ans
    }
    
    return 0;
}
