/*
  https://github.com/sahilbansal17/Competitive_Coding/

  Name: Anil Khatri (@imkaka)
  Email-Id: anil.soccer.khatri@gmail.com

*/
// STL -> priority_queue foe creating min Heap.
// as discussed in "stl_priority_queue.cpp" here we will talk about a Constructor provided
// that can be used to function priority_queue in reverse order (minimum first)
// Like Min Heap.

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

// Function Decleration
void Print(priority_queue<int,vector<int> ,greater<int>>);

int main(){

  //priority_queue supports a constructor that requires two extra arguments to make it min heap.
  // priority_queue <Type, vector<Type>, ComparisonType > min_heap;

  // We can use any Custom Type in the Constructor but of understanding purpose we will use int here.

  priority_queue<int , vector<int> ,greater<int>> pq;

  // greater<int>() => Binary function object class whose call returns whether the its first argument compares greater 
  //              than the second (as returned by operator >).

  // Now we wil do all stuffs as Min Heap.

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
  //We can excess the min of all the elements using top() => reference to topmost element.

  cout << "The Maximum Element : " << pq.top() <<endl;

  // Extracting the min element => pop()

  cout << "1.pop(): " << pq.top()<<endl;
  pq.pop();

  cout << "2.top(): " << pq.top() <<endl;

  // Printing all the Elements.
  cout << "Last Print: ";
  Print(pq);

return 0;
}

// Function Defination to print all values.
 void Print(priority_queue<int,vector<int> ,greater<int> > pq ){

  priority_queue <int, vector<int> ,greater<int> > copy = pq;
    while (!copy.empty())
    {
        cout << '\t' << copy.top();
        copy.pop();
    }
    cout << '\n';
 }