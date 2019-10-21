#include <iostream>
using namespace std;

int main()
{
int g=1;
long a[1000000],n,i;
cin>>n;
for( i=0;i<n;i++)
cin>>a[i];
for(i=0;i<n-1;i++)
{
if(a[i]>a[i+1])
{
g++;
}
}
cout << g;
return 0;
