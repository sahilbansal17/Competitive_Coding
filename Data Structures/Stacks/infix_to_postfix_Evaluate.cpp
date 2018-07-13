/*
  https://github.com/sahilbansal17/Competitive_Coding/

  Name: Anil Khatri (@imkaka)
  Email-Id: anil.soccer.khatri@gmail.com

*/

// Convert Infix Notation to Postfix Notation and Evaluate it.
// It is one of the Populer Application of Stack Data Structure.

// Input Infix Expression must be in proper format. ==>  "3+2*(2^2-9)^(2-3/3)+3"
// Operands and Operators, both must be single character.
// Only '+' , '-' ,'*' ,'/' and '^' (Exponentiation) operators are expected.

#include<iostream>
#include<string>
#include<stack>
#include<cmath>

using namespace std;

// Function Prototypes

int precedence(char);
// It return the Precedence of any Operator.
// @param => (char) => operator

int evaluatePostfix(string);
// It evaluate and return the result of expression
// @param => (string) => postfix Expression

string infixToPostfix(string);
// It Convert the Infix to postfix and return the resulted Expression.
// @param => (string) => infix Notation


int main(){

    string expression;
    cout << "Please Input a Infix Expression in Proper Format:";
    cin >> expression;
    cout << "Infix Expression: "<< expression <<endl;
    
    string postExpression = infixToPostfix(expression);
    cout << "Postfix Expression: "<< postExpression <<endl;

    int result = evaluatePostfix(postExpression);
    cout<< "Result: "<<result<<endl; 
return 0;
}

// Function Definations

int precedence(char oper){

  if( oper == '^') 
    return 3;
  else if( oper == '*'|| oper == '/') 
    return 2;
  else if( oper == '+'|| oper == '-')
    return 1;
  else
    return -1;
}

// Infix to Postfix

string infixToPostfix(string exp){

  //initialize stack
  stack<char> bucket;
  string postfix;
  
  // Iterate through every char
  for( int i=0; i< exp.size(); i++){
    
    // if the scanned char is operand (0-9) add it to output string
    if(exp[i] >= 48 && exp[i] <= 57)
      postfix+=exp[i];
    
    // if scanned char is '(' push it on stack

    else if(exp[i] == '(')
      bucket.push('(');
    
    // If the scanned char is an ‘)’ pop and add to output string until '('
    else if(exp[i] == ')')
      {
        while((!bucket.empty()) && bucket.top() != '(')
          {
            char c = bucket.top();
            bucket.pop();
            postfix += c;
          }
          if(bucket.top() == '(')
            {
              char c = bucket.top();
              bucket.pop();
            }
        }
         
    //If an operator is scanned 
        else{
          while((!bucket.empty()) && precedence(exp[i]) <= precedence(bucket.top()))
          {
            char c = bucket.top();
            bucket.pop();
            postfix += c;
          }
            bucket.push(exp[i]);
        }
 
    }
    //Pop all the remaining elements from the stack
    while(!bucket.empty())
    {
        char c = bucket.top();
        bucket.pop();
        postfix += c;
    }
     
  return(postfix);
}

// Evaluation of the postfix Expresstion

int evaluatePostfix(string exp){

  stack<int> buck; 

  
  // Scan one char at a time.
  for(int i = 0; i<exp.size(); i++){

    //if it is a int push to stack
    if(exp[i] >= 48 && exp[i] <= 57)
      buck.push(exp[i] - '0');

    //if a operator pop two elements from stack evaluate and then push it back
    else if((exp[i] >=42 && exp[i] <= 47) ||exp[i] == 94){

      int a = buck.top(); buck.pop();
      int b = buck.top(); buck.pop();

      switch(exp[i])
        {
          case '+':
            buck.push(a+b);
            break;
          case '-':
            buck.push(b-a);
            break;
          case '*':
            buck.push(a*b);
            break;
          case '/':      
            buck.push(b/a);
            break;
          case '^':
            buck.push(pow(b,a));
            break;
        }
    } 
  }

  return(buck.top());

}

// Time Complexity O(n)     
// Space Complexity O(n) 