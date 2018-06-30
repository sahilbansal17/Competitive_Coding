#include<iostream>
/* To implement queue container adaptors to our code we need to include the queue library
which includes predefined functions such as push(),pop(),front(),back() etc which are necessary
in implementing a queue */
#include<queue>
#include<stack>
using namespace std;

void displayQueue(queue <int> q1){

    //Checking whether the queue is empty or not
    //empty() function returns false if the queue is not empty otherwise true
    while(q1.empty() == false){
        //Displays the top element on the queue
        //Since front() returns the reference to the front element of the queue
        cout << q1.front() << " ";
        //pop() pops the top of the stack
        q1.pop();
    }
    cout << endl;
}

void checkEmpty(queue <int> q1){
    if(q1.empty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }
}

//Reversing a queue by recursion
void reverseQueue(queue <int> &q){
    //Base Case
    if(q.empty())
        return;
    else{
        //Storing the front element of the queue
        int temp = q.front();
        //Removing the front element
        q.pop();
        //Calling the reverseQueue() on the remaining elements
        reverseQueue(q);
        q.push(temp);
    }
}

int main(){
    //creating a stack which holds integer values
    queue <int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    /* Complexity of operation in stack STL
       As each operation takes constant time therefore the time complexity of all the operations
       in queue is constant
        Suppose we have to push n elements onto the queue
          therefore time complexity = c * n =  O(C')
          where C' = C*n
                c = constant for each push operation
                n = number of elements

        Space Complexity is dependent on number of elements in the queue
        Similarly all other operations takes constant time
    */

    checkEmpty(q); //Check whether the queue is empty or not

    cout << "The queue elements are " << endl;
    displayQueue(q); // calling the displayQueue method and passing stack as argument

    cout << "The element at the front of the queue is " << q.front() << endl;
    cout << "The element at the back of the queue is " << q.back() << endl;
    //displays the size of the queue
    cout << "The size of the queue is " << q.size() << endl;
    q.pop();
    cout << "After popping the queue elements are" << endl;
    displayQueue(q);
    cout << "The elements of queue before reversing " << endl;
    displayQueue(q);
    reverseQueue(q);
    cout << "After reversing elements of queue are" << endl;
    displayQueue(q);
    return 0;
}
