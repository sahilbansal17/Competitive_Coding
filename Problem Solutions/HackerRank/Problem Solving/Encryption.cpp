// Name: Neha Gupta
// Email-id: nehaguptang.ng@gmail.com

//Output Format  -: Print the encoded message on one line as described.

//Sample Input :- haveaniceday

//Sample Output :- hae and via ecy


#include <bits/stdc++.h>
#include<string>
#include<cmath>

using namespace std;


string encryption(string s) 
    {
    
        int length,sq,sq1,j;
        
        string yo;                  //Resulatant string
        
        length = s.length();          //to find length of inputed string
        
        sq=sqrt(length);
        
        if(sq*sq==length)               //if length is perfect square then row size is equal to column size.
            sq1=sq;
        
        else                            //else increment the column length 
        sq1=sq+1;
    
        for(int i=0;i<sq1;i++)          //looping till the column length for output
        {
        
            j=i;                        //inner loop initilaisation
             while(j<length)            //looping till the length of input string
               {
                    yo=yo+s.at(j);      //adding element columnnwise present at location j
                    j=j+sq1;            //columnwise addition
                }
        yo=yo+" ";
    }
    
return yo;                              //return following result 'yo' as output.





}

int main()                      //main function of program
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
