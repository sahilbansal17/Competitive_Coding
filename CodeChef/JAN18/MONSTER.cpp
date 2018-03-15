//only for 1st sub task
#include<bits/stdc++.h>
using namespace std;
long long int n1,alive;
long long int y;
long long int h[200000];
void subArray(long long int arr[], long long int n)
{
    unsigned int opsize = 1<<n;
    unsigned long long int s=0;
 
    for (int counter = 1; counter < opsize; counter++)
    {s=0;
        for (int j = 0; j < n; j++)
        {
            if (counter & (1<<j))
                s+=arr[j];
                
        }
        if (s<n1){
                if (h[s]>0){
                    h[s]-=y;
                    if (h[s]<=0){
                        alive--;}}}
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n1;
    alive=n1;
    long long z[1000];
    for (int i=0;i<n1;i++)
    {
        cin>>h[i];
    }
    long int q;
    long long int x,i=0;
    cin>>q;
    while(q--)
    {
        i=0;
        cin>>x>>y;
        if (h[0]>0){
        h[0]-=y;
        if (h[0]<=0) {alive--;}
        }
        while(x){
            long long p= (int)(1<<(int)log2(x));
            x-=p;
            if (p<n1)
            {
                z[i]=p;
            i++;
            }
        }
        subArray(z,i);
        cout<<alive<<endl;
    }
    return 0;
} 
