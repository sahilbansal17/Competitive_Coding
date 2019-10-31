#include <iostream>
#include <vector>
using namespace std;
/*
int main()
{
    vector<short int> answer;
    unsigned short int t;
    cin>>t;
    
    for (int i=0; i<t; i++)
    {
        unsigned short int n;
        cin>>n;
        unsigned int attack[n], defense[n];
        
        for (int j=0; j<n; j++)
        {
            cin>>attack[j];
        }
        for (int j=0; j<n; j++)
        {
            cin>>defense[j];
        }
        
        int result =-1;
        
        if ((attack[1]+attack[n-1]) < defense[0])
        {
            int def = defense[0];
            if (def > result)
            {
                int temp = def;
                def = result;
                result = temp;
            }
            
        }
        
        if ((attack[0]+attack[n-2]) < defense[n-1])
        {
            int def = defense[n-1];
            if (def > result)
            {
                int temp = def;
                def = result;
                result = temp;
            }
            
        }
        
        for (int h=1; h<n-1; h++)
        {
            int def = defense[h];
            if ((attack[h-1]+attack[h+1]) < defense[h])
            {
                if (def > result)
                {
                    int temp = def;
                    def = result;
                    result = temp;
                }
                
            }
        }
        answer.push_back(result);
    }
    
    for (int g=0; g<t; g++)
    {
        cout<<answer[g]<<"\n";
    }
    
    return 0;
}
*/
