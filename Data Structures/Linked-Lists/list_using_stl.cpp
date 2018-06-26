#include<iostream>
#include<vector>
#include<list>/*header file required for list implementation*/
using namespace std;
//display functions
void displayInt(list <int> l)
{   // Traversal of  list
    for(list <int> :: iterator i=l.begin();i!=l.end();i++)
        cout<<*i<<" ";
    cout<<endl;
}
void displayChar(list <char> l)
{
    for(list <char> :: iterator i=l.begin();i!=l.end();i++)
        cout<<*i<<" ";
    cout<<endl;
}
bool greaterThan3(int val)
{
  return(val>3);
}
/* Lists are used to implement doubly linked lists in STL*/

int main()
{
    /*constructors*/
    vector <int> num(4,5);
    list<int> l1;                          //empty constructor
    list<char> l2(5,'a');                  //fill constructor
    list<char> l3(l2);                    //copy constructor
    list<int> l4={1,2,3,4};                 //initializer_list constructor
    list<int> l5(num.begin(),num.end());   //range constructor

    cout<<"l1: ";
    displayInt(l1);
    cout<<"l2: ";
    displayChar(l2);
    cout<<"l3: ";
    displayChar(l3);
    cout<<"l4: ";
    displayInt(l4);
    cout<<"l5: ";
    displayInt(l5);


    /* Insertion*/
    cout<<"Inserting element in l5: ";
    l5.insert(l5.begin(),9);//inserting single element before given position
    displayInt(l5);
    cout<<"Inserting element in l4: ";
    list<int>::iterator iter=l4.end();
    l4.insert(iter,{5,6,7});//inserting multiple elements at given position
    displayInt(l4);
    cout<<"Inserting element in l1: ";
    l1.insert(l1.begin(),2,10);//inserting same element multiple times
    displayInt(l1);
    cout<<"Inserting element at front of l1: ";
    l1.push_front(3);//Insert elements at the front
    displayInt(l1);
    cout<<"Inserting element at end of l2: ";
    l2.push_back('b');
    displayChar(l2);


    /*Deletion*/
    cout<<"Deleting element at front of l1: ";
    l1.pop_front();//Delete element at the front
    displayInt(l1);
    cout<<"Deleting element at end of l2: ";
    l2.pop_back();
    displayChar(l2);
    cout<<"Deleting element at index 2 in l5: ";
    list <int> :: iterator i=l5.begin();
    i++;i++;
    l5.erase(i);//deleting single element at given position
    displayInt(l5);
    cout<<"Deleting elements in given range in l4: ";
    list <int> :: iterator it=l4.begin();
    it++;it++;it++;it++;
    l4.erase(it,l4.end());//deleting multiple elements in given range including first but not last
    displayInt(l4);
    cout<<"Deleting element with a value 5 in l5: ";
    l5.remove(5);//deleting element with specific value
    displayInt(l5);
    cout<<"Deleting element greater than 3 in l4: ";
    l4.remove_if(greaterThan3);//delete elements satisfying given condition
    displayInt(l4);


    /*Reversal*/
    cout<<"Reversing list l4: ";
    l4.reverse();
    displayInt(l4);


    /*Splicing*/
    cout<<"Splicing l4 with l5: ";
    l4.splice(l4.begin(),l5);//transfer elements from one list to another after given position
    displayInt(l4);
    list<int> l6={10,11,12};
    cout<<"Splicing l5: ";
    l5.splice(l5.begin(),l6,l6.begin());//splicing a list with single element of another list after given position
    displayInt(l5);
    cout<<"Splicing l1 with l4 in range[1,4): ";
    l1.splice(l1.begin(),l4,l4.begin(),l4.end());//transfer elements in a given range from(including first) one list to another
    displayInt(l1);

    return 0;

}

/* Operation        Complexity
   Insertion        O(1)
   Deletion         O(1)
   Traversal        O(n)
   Reversal         O(n)
   Splicing	    O(n)
*/
