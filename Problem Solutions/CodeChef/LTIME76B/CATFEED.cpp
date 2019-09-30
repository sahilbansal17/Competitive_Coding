#include <bits/stdc++.h>
// Author: @NavonilDas
// Question: https://www.codechef.com/LTIME76B/problems/CATFEED
using namespace std;

int main(){
        int t;
        cin>>t;
        while(t--){
            int N,M;
            cin>>N>>M;
            vector<int> ar(M);

            for(int i=0;i<M;++i)
                cin>>ar[i];

            vector<int> cats(N,0); // Create a array to keep track of which cat has eaten how much meal (frequency of eating)
            bool flg = false; // flag if a cat has not eaten with respect to others

            for(int i=0;i<M;++i){
                ++cats[ar[i]-1]; // Increment the frequency

                int Max = *min_element(cats.begin(),cats.end()); // Find the minimum can eaten

                /// if any cat has eaten more than one can extra then set flag to true
                for(int k=0;k<N;++k){
                    if(cats[k] > Max+1) flg = true;
                }
            }
                // if Flag is set then the order is wrong else it is right
                if(flg){
                    cout<<"NO"<<endl;
                }
                else cout<<"YES"<<endl;

        }
        return 0;
}
