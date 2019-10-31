#include <iostream>
#include <vector>
using namespace std;
/*
int main()
{
    vector<unsigned int> result;
    unsigned int t;
    cin>>t;
    
    for(int y=0;y<t;y++)
    {
        unsigned int n=0;
        cin>>n;
        string arr[n];
        bool ing[26] = {true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true};
        
        for (unsigned short int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        
        unsigned int result_num=0;
        
        for (unsigned short int pos1=0; pos1<arr[0].length(); pos1++)//points character of first string
        {
            unsigned int strvalid = 0;
            int ascii = (int) arr[0].at(pos1);
            ascii = ascii-97;
            
            if(ing[ascii] == false)
            {
                continue;
            }
            
        label:
            for (unsigned short int j=1; j<n; j++)
            {
                unsigned int count=0;
                
                    for (unsigned short int pos2=0; pos2<arr[j].length(); pos2++)//points character of nth string
                    {
                        if (arr[0].at(pos1) == arr[j].at(pos2))
                        {
                            strvalid++;
                            break;
                        }
                        count++;
                    }
                
                if (count==arr[j].length())
                {
                    break;
                }
            }
            if (strvalid==n-1)
            {
                result_num++;
            }
            
            ing[ascii] = false;

        }
        result.push_back(result_num);
    }

    for (unsigned short int g=0; g<t; g++)
    {
        cout<<result[g]<<"\n";
    }

    return 0;
}
*/
