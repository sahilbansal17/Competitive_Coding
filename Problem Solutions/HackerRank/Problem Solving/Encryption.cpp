#include <bits/stdc++.h>
#include<string>
#include<cmath>

using namespace std;

// Complete the encryption function below.
string encryption(string s) {
    int length,sq,sq1,j;
    string yo;
    length=s.length();
    sq=sqrt(length);
    if(sq*sq==length)
     sq1=sq;
     else
        sq1=sq+1;
    //cout<<sq<<" "<<sq1<<endl;
    for(int i=0;i<sq1;i++)
    {
        //cout<<i;
        j=i;
        while(j<length)
        {
        yo=yo+s.at(j);
        j=j+sq1;
        }
        yo=yo+" ";
    }
    
return yo;





}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
