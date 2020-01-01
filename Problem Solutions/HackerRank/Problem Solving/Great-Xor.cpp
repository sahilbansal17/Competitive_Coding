//Nmae: Neha Gupta
//Email: nehaguptang.ng@gmail.com
//Given a long integer x , count the number of values of a satisfying the following conditions:
//a XOR x > x 
//and
// 0 < a < x

#include <bits/stdc++.h>

using namespace std;

// theGreatXor function below.
long theGreatXor(long x) 
{
    long result , num=0 , a ;
    int total , o=0 , z=0 ;         //here o are number of ones in binary form and z are number of zeroes in binary form of x
    
    a=x;                        //saving value of x in a for future use
    
    while(x!=0)                 //finding number of zeroes and ones in binary form of x
        
    {
        
        if( x & 1 == 1 )        //if number is one
            o++;                   //increment number of ones 'o'
        
        else                    //else if digit is zero   
            z++;                //increment number of zeroes 'z'            
        x=x >> 1 ;                //right shift number
    }
    
    total = o + z ;             //adding 'o' and 'z' to get total number of digit
    
    while(total!=0)            //loop to find values of a
    {
        num=num+pow(2,total-1);     //to get number 2's power till length - 1
        total--;
    }
    result=num^a;                   //xor initial number with num
    
    return result;                  //return result

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        long x;
        cin >> x;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        long result = theGreatXor(x);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
