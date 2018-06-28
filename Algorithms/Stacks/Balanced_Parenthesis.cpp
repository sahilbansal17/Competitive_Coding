/*
This code is to check the balanced parenthesis of the given string. 
We process each characters of the string only once. 
If the processed character is opening parenthesis it is pushed to the stack.
If the processed character is a closing parenthesis, it is compared with top of stack.
If while processing, stack is empty or character at top of stack does not match with corresponding closing parenthesis,
the given string is not balanced.
Else pop the top of stack and continue processing.
If after processing, stack is empty, it means the given string is balanced else it is not balanced.
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if character x is an opening parenthesis and character y is an closing parenthesis 
// or character x is 'less than' and character y is 'greater than' operator
bool checkCharacter(char x, char y) 
{
	if ((x=='(' && y==')') || (x=='{' && y=='}') || (x=='[' && y==']') || (x=='<' && y=='>')) // compare characters
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool checkBalancedParenthesis(string s) // Function to check if the string has balanced paranthesis or not
{
	stack<char> st; // character stack to store given string characters
	int l=s.length();
	for(int i=0;i<l;i++)
	{
		if(s[i]=='(' || s[i]=='{' || s[i]=='[') // if the character of the string is opening paranthesis, push it to stack
		{
		        st.push(s[i]);
		}
		else if(s[i]==')' || s[i]=='}' || s[i]==']')  // if character is closing parenthesis, compare with stack top
		{
			if(st.empty() || checkCharacter(st.top(),s[i])==false) 
			{
			      // if no element in stack 
			      // or character at top does not match with corresponding current character
			      return false;
			}
			else
			{
			      st.pop(); // if matches , pop the top of stack 
			}
		}
	}
	if(st.empty()) // if top is -1 it indicates that number of opening parenthesis is same as closing parenthesis
	 return true;
	else
	 return false;
}
int main() 
{
	int test;
	cout<<"Enter the number of strings you want to check"<<endl;
	cin>>test;
	while(test-->0)
	{
	    string s;
            cout<<"Enter the string you want to check"<<endl;
	    cin>>s;
	    if(checkBalancedParenthesis(s)==true) // check if input string has balanced parenthesis or not
	       cout<<"BALANCED"<<endl;
	    else
	       cout<<"NOT BALANCED"<<endl;
	}
	return 0;
}

/*   
TIME COMPLEXITY: O(L)
For the given strings, we have to process all the characters of the strings only once.
So the time complexity is O(L), where L is length of string 
*/
