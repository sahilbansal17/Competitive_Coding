#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n>4)   //cases for n<=4 dealt separately below
    {
        cout<<n<<endl;
        if(n%2==0)  //case when n is EVEN
        {
            for(int i=1;i<=n;i++)
            {
                if(i%2==1)
                {
                    cout<<((i+1)/2)<<" ";   //case when index position is odd
                }
                else
                {
                    cout<<((n+i))/2<<" ";   //case when index position is even
                }
                
            }
        }
        else   //case when n is ODD
        {
            for(int i=1;i<=n;i++)
            {
                if(i%2==1)
                {
                    cout<<((i+1)/2)<<" ";
                }
                else
                {
                    cout<<((n+1+i))/2<<" ";
                }
                
            }
        }
        
    }
    else if(n==4)
    {
        cout<<4<<endl;
        cout<<"3 1 4 2";
    }
    else if(n==3)
    {
        cout<<2<<endl;
        cout<<"1 3";
    }
    else 
    {
        cout<<1<<endl;
        cout<<1;
    }
    
    return 0;
}