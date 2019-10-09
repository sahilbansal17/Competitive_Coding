#include <iostream>
using namespace std;
#include<bits/stdc++.h>
typedef long long ll;
int main() {
    int t;
    cin >> t;
    for(int l=0;l<t;l++){
        ll n,d,digits;
        cin >> n>>d;
        ll i,ten=10;
        for( i=1;i<=18;i++){
            if(ten>n)
            break;
            else ten=ten*10;
        }
        digits=i;
        ll a[digits],b[digits],ans[digits];
        for(ll i=digits-1;i>=0;i--){
            a[digits-i-1]=n/(ll)pow(10,i);
            b[digits-i-1]=n/(ll)pow(10,i);
            n=n-n/(ll)pow(10,i)  * (ll)pow(10,i);
        }
        
        ll temp=0;
        for(i=0;i<digits;i++){
            sort(a+temp,a+digits);
            if(temp>digits-1) break;
            if(a[temp]>=d)
            break;
            ans[i]= a[temp];
            for(ll j=temp;j<digits;j++){
                if(b[j]==a[temp])
                {
                    temp=j+1;
                    break;
                }
            }
            
            for(ll k=temp;k<digits;k++){
                a[k]=b[k];
            }
            
        }
        
        for(int p=0;p<digits;p++){
            if(p<i)
            cout << ans[p];
            else cout << d;
        }
        cout <<endl;
    }
	return 0;
}
