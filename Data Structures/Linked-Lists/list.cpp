// C++ STL List and the basic implementations on it
#include<iostream>
// we must include this library to use a vector
// the implementation of list here is doubly linked list
#include<list>
using namespace std;
int main(){

    // declaring an empty list of integers
    list<int> l;
    // computing the initial size which is zero
    cout <<"The initial size of the list is " << l.size() << endl;

    int n,num;
    cout << "Enter the number of elements which you want to insert into the list" << endl;
    cin >> n;

    cout << "Enter the elements into the list" << endl;
    for(int i=0; i<n; i++){
        cin >> num;
        // function push_back is used to insert an element into the back of the list
        l.push_back(num);
    }

    //pushing an element to the front
    cout << "Enter the element which you want to insert into the front of the list" << endl;
    cin >> num;
    l.push_front(num);

    int pos;
    cout << "Enter the element and the position at which you want to insert into the list" << endl;
    cin >> num >> pos;
    list<int>::iterator itr;

    // count of elements traversed till we reach at a specific position
    int prev = 0;
    for(itr = l.begin(); prev < pos -1; itr++){
        prev++;
    }
    l.insert(itr,num);


    //Printing the elements of the list using iterator
    cout << "The element of the list are " << endl;
    list<int>::iterator it;
    for(it=l.begin(); it!=l.end(); it++){
        cout <<*it<< " ";
    }
    cout << endl;

    //Some common operations on the list

    //deletion of elements from the list
    l.pop_back();
    // to remove an element form the from of the list
    l.pop_front();

    cout << "After deletion operations the elements of the list are" << endl;
    for(it=l.begin(); it!=l.end(); it++){
        cout <<*it<< " ";
    }
    cout << endl;

    l.reverse();
    cout << "After reversing the list the new list is " << endl;
    for(it=l.begin(); it!=l.end(); it++){
        cout <<*it<< " ";
    }
    cout << endl;


    return 0;
}
/* Time Complexity
   The insertion usually takes constant time.However if we want to insert
   at specific position we need to traverse the list thus that operation
   takes linear time complexity

   Space Complexity depends upon number of elements in the list i.e thus
   linear O(n)
*/
