#include<iostream>
#include<string> //Using string library    
using namespace std;

int main() {
    int q; //Number of queries
    cin>>q;

    for(int i=0;i<q;i++) {
        
        string s;
        cin>>s;

        if(s.size()>10){ //Finding length of s; .size() is a function of 'string'
            
            int j=0;
            
            while(s[j]!='\0') //till j reaches index after last character of s
                j++;
            
            j--; //j becomes index of last char of s
            
            cout<<s[0]<<j-1<<s[j]; //first char + no.of chars in between + last char
        }
        else cout<<s; //if length <= 10
    }
}
