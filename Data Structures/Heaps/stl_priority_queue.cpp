/*
  https://github.com/sahilbansal17/Competitive_Coding/

  Name: Anil Khatri (@imkaka)
  Email-Id: anil.soccer.khatri@gmail.com

*/

// (STL priority_queue) => In this we will discuss about a Container that provide constant
// time extraction of the largest element (Priority) at the expense of Log time insertion.
// Similer to heap.
// we will explore all the frequent & available functions.

// We will also discuss about a special Constructor provided by priority_queue to function like Min_Heap() in other Article.

#include<iostream>
#include<queue>   

using namespace std;

// Function Decleration
void Print(priority_queue<int>);

int main(){

  priority_queue<int> pq ;

  // Printing the Initial size of pq '0'
  cout << "The initial size of priority_queue : " << pq.size()<<endl;

  //pushing new values to priority queue.=> push()

  cout << "Enter No of elements to push in priority_queue: "<<endl;
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    int x;
    cin >>x;

    pq.push(x);
  }

   cout << "Print After Push:";
   Print(pq);
  // We can use emplace() too to insert new value
  // emplace() vs push()
  // When we use push(), we create an object and then insert it into the priority_queue. With emplace(), 
  // the object is constructed in-place and saves an unnecessary copy. (https://www.geeksforgeeks.org/emplace-vs-insert-c-stl/)

  pq.emplace(12);
  pq.emplace(50);
  
  cout << "Print after emplace (12), (50) :";
  Print(pq);
  //We can excess the max of all the elements using top() => reference to topmost element.

  cout << "The Maximum Element : " << pq.top() <<endl;

  // Extracting the max element => pop()

  cout << "1.pop(): " << pq.top()<<endl;
  pq.pop();

  cout << "2.top(): " << pq.top() <<endl;

  // Printing all the Elements.
  cout << "Last Print: ";
  Print(pq);

return 0;
}

// Function Defination to print all values.
 void Print(priority_queue<int> pq ){

  priority_queue <int> copy = pq;
    while (!copy.empty())
    {
        cout << '\t' << copy.top();
        copy.pop();
    }
    cout << '\n';
 }

 // Time Complexity  =>
 //                     pop() => O(1)  
 //                     push(x)/emplace(x) = > O(LogN)   -> We have to traverse heap data structure to insert the value at right place.
 //                     empty() => O(1)
 //                     top()   => O(1)

 // Space Complexity =>  O(N)   => Storing the Elements 
