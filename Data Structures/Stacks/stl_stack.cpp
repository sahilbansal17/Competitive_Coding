#include<iostream>
/* To implement stack container adaptors to our code we need to include the stack library
which includes predefined functions such as push() , pop() ,top() etc which are necessary
in implementing a stack */
#include<stack>
using namespace std;

void displayStack(stack <int> s1){

    //Checking whether the stack is empty or not
    //empty() function returns false if the stack is not empty otherwise true
    while(s1.empty() == false){
        //Displays the top element on the stack
        //Since top() returns top element so i have printed it out
        cout << s1.top() << " ";
        //pop() pops the top of the stack
        s1.pop();
    }
    cout << endl;
}

void checkEmpty(stack <int> s1){
    if(s1.empty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }
}

void sortedInsert(stack<int> &s,int item){
    //Checkig if stack is empty or if the top element has value greater than item
    if(s.empty() || item < s.top()){
        s.push(item);
        return;
    }
    //storing the top of the stack
    int temp = s.top();
    //removing the top element from the stack
    s.pop();
    //Calling repeatedly until the condition is satisfied
    sortedInsert(s,item);
    //pushing the elements which were popped out back to the stack again
    s.push(temp);
}

void sortStack(stack<int> &s){
    //Checking if the stack is empty or not
    //Also act as a base case for the recursive call
    if(s.empty())
        return;
    //Store the top element in the temp
    int temp = s.top();
    //Removing the topmost element
    s.pop();
    //Recursive call to the sortStack() by passing remaining stack
    sortStack(s);
    //Calling sortedInsert() to insert elements in sorted order
    sortedInsert(s,temp);
}

int main(){
    //creating a stack which holds integer values
    stack <int> s;
    s.push(2);
    s.push(3);
    s.push(1);

    /* Complexity of operation in stack STL
       As each operation takes constant time therefore the time complexity of all the operations
       in stack is constant
        Suppose we have to push n elements onto the stack
          therefore time complexity = c * n =  O(C')
          where C' = C*n
                c = constant for each push operation
                n = number of elements

        Space Complexity is dependent on number of elements in the stack
        Similarly all other operations takes constant time
    */
    checkEmpty(s); //Check whether the stack is empty or not

    cout << "The stack elements are " << endl;
    displayStack(s); // calling the displayStack method and passing stack as argument
    s.push(4);
    s.push(5);
    //displays the size of the stack
    cout << "The size of the stack is " << s.size() << endl;
    s.pop();
    cout << "After popping the stack elements are" << endl;
    displayStack(s);
    s.push(8);
    s.push(25);
    s.push(15);
    cout << "Before sorting stack elements are " << endl;
    displayStack(s);
    sortStack(s);
    cout << "After sorting stack elements are " << endl;
    displayStack(s);
    return 0;
}
