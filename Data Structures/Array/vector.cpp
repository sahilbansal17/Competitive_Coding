// C++ STL Vector and the basic implementations on it
#include<iostream>
// we must include this library to use a vector
#include<vector>
using namespace std;
int main(){

    vector<int> v;
    // computing the initial size which is zero
    cout <<"The initial size of the vector is " << v.size() << endl;
    int n,num;
    cout << "Enter the number of elements which you want to insert into the vector" << endl;
    cin >> n;

    cout << "Enter the elements into the vector" << endl;
    for(int i=0; i<n; i++){
        cin >> num;
        // function push_back is used to insert an element into the back of the vector
        v.push_back(num);
    }

    //Printing the elements of the vector
    for(int i=0; i<n; i++){
        cout << v[i] << " ";
    }
    cout << endl;

    // printing vector elements by using at() method
    for(int i=0; i<n; i++){
        cout << v.at(i) << " ";
    }
    cout << endl;

    // begin() and end() returns an iterator to the first and last element
    //using iterator to print the elements of vector
    vector<int>::iterator it;
    for(it = v.begin(); it!=v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    // calculating the size maximum size and capacity
    cout << "The size of the vector is " << v.size() << endl;
    // capacity returns the maximum number of elements that can be inserted without resizing
    cout << "The current capacity is " << v.capacity() << endl;
    // returns the maximum possible size of the vector
    cout << "The maximum size of the vector is " << v.max_size() << endl;

    //checking if the vector is empty
    if(v.empty()){
        cout << "The vector is empty" << endl;
    }
    else{
        cout << "The vector is not empty" << endl;
    }

    cout << "The element present at the front is " << v.front() << endl;
    cout << "The element present at the back is " << v.back() << endl;

    // to insert the element at any position in the vector
    int pos;
    cout << "Enter the element and the postion at which you want to insert" << endl;
    cin >> num >> pos;
    v.insert(v.begin()+pos-1,num);

    cout << "After insertion the new vector is " << endl;
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;

    // deletion operations

    // removes the last element from the vector
    v.pop_back();
    // erase to remove the element at particular position
    cout << "Enter the position at which you want to remove element" << endl;
    cin >> pos;
    v.erase(v.begin()+pos-1);

    cout << "After deletion operations the final vector elements is " << endl;
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;

    // to clear the vector
    v.clear();
    if(v.empty()){
        cout << "The vector is empty" << endl;
    }
    else{
        cout << "The vector is not empty" << endl;
    }
    return 0;
}

/* Time Complexity
   For insertion in worst case O(n) because if vector is full inserting a
   new element results in formation of a new vector of double vector and
   copying of elements from previous vector into it.
   In all other cases it is O(1)
   For all other operations time complexity is O(1)
   Space Complexity is dependent on number of elements in vector i.e O(n)
*/
