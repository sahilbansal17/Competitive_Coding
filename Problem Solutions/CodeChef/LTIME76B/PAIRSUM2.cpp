#include <bits/stdc++.h>
// Author: @NavonilDas
// Question: https://www.codechef.com/LTIME76B/problems/PAIRSUM2

template <class T> void Swap(T &a,T &b){T c=a;a=b;b=c;}

using namespace std;

/***
 * Alternative Methods
 * for query where the difference of index is odd (a,b) where b>a
 * we can loop through b-1 to a in which we subtract alternating elements
 * example
 * 4 5 6 7
 * a = 1 b = 4
 * ANSWER = +6 - 5 + 4 = 5
 * This can also be written as +6 + 5 + 4 - 2*(5)
 * the problem with this algorithm was that for larger values of n,q it will produce TLE
 * as the complexity id O(NQ) for ONE ARRAY where N is size of Array and Q is No of Queries.
 * So we store the Sum of alternating elements and sum in range in an prefix array before 
 * execution of query
 * */

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int> ar(n-1),br(n-1); // Two vectors to store prefix sum

        for(int i=0;i<(n-1);++i){
            cin>>ar[i]; // input the array
            br[i] = ar[i]; // copy the array
        }
        for(int i=1;i<n-1;++i){
            ar[i] += ar[i-1]; /// Prefix sum all the numbers from 0 to i
            if(i >= 2) br[i] += br[i-2]; // Prefix sum add all the alternating elements as we need to subtract it from answer
        }
        long ans = 0;
        while (q--){
            int a,b;
            cin>>a>>b;
            ans = 0;
            if(b>a) Swap<int>(a,b); /// a should always be greater than b if not then swap
            /// Check if the gap between the index is odd or not
            /// We cannot find the answer for those index whose difference is even as no of unknown variables are more than no of equations
            if(((b-a)%2)){
                ans += (ar[a-2] - (b>1?ar[b-2] : 0)); // Sum between the range a-1 to b-2
                ans -= 2*((a>2?br[a-3]:0) - (b>1?br[b-2] : 0)); // Subtract the sum of alternating elements from the result
                cout<<ans<<endl;
            } 
            else cout<<"UNKNOWN\n";
        }
    }
	return 0;
}