#include<iostream>
#include<vector>
#include<forward_list>/*header file required for forward list implementation*/
using namespace std;
//display functions
void displayInt(forward_list <int> f)
{   // Traversal of forward list
    for(forward_list <int> :: iterator i=f.begin();i!=f.end();i++)
        cout<<*i<<" ";
    cout<<endl;
}
void displayChar(forward_list <char> f)
{
    for(forward_list <char> :: iterator i=f.begin();i!=f.end();i++)
        cout<<*i<<" ";
    cout<<endl;
}
bool greaterThan3(int val)
{
  return(val>3);
}
/* Forward lists are used to implement singly linked lists in STL*/

int main()
{
    /*constructors*/
    vector <int> num(4,5);
    forward_list<int> fl1;                          //empty constructor
    forward_list<char> fl2(5,'a');                  //fill constructor
    forward_list<char> fl3(fl2);                    //copy constructor
    forward_list<int> fl4={1,2,3,4};                 //initializer_list constructor
    forward_list<int> fl5(num.begin(),num.end());   //range constructor

    cout<<"fl1: ";
    displayInt(fl1);
    cout<<"fl2: ";
    displayChar(fl2);
    cout<<"fl3: ";
    displayChar(fl3);
    cout<<"fl4: ";
    displayInt(fl4);
    cout<<"fl5: ";
    displayInt(fl5);


    /* Insertion*/
    cout<<"Inserting element in fl5: ";
    fl5.insert_after(fl5.begin(),9);//inserting single element after given position
    displayInt(fl5);
    cout<<"Inserting element in fl4: ";
    forward_list<int>::iterator iter=fl4.begin();
    iter++;iter++;iter++;
    fl4.insert_after(iter,{5,6,7});//inserting multiple elements at given position
    displayInt(fl4);
    cout<<"Inserting element in fl1: ";
    fl1.insert_after(fl1.before_begin(),2,10);//inserting same element multiple times
    displayInt(fl1);
    cout<<"Inserting element at front of fl1: ";
    fl1.push_front(3);//Insert elements at the front
    displayInt(fl1);


    /*Deletion*/
    cout<<"Deleting element at front of fl1: ";
    fl1.pop_front();//Delete element at the front
    displayInt(fl1);
    cout<<"Deleting element at index 2 in fl5: ";
    forward_list <int> :: iterator i=fl5.begin();
    i++;
    fl5.erase_after(i);//deleting single element after given position
    displayInt(fl5);
    cout<<"Deleting elements in given range in fl4: ";
    forward_list <int> :: iterator it=fl4.begin();
    it++;it++;it++;it++;
    fl4.erase_after(it,fl4.end());//deleting multiple elements in given exclusive range
    displayInt(fl4);
    cout<<"Deleting element with a value 5 in fl5: ";
    fl5.remove(5);//deleting element with specific value
    displayInt(fl5);
    cout<<"Deleting element greater than 3 in fl4: ";
    fl4.remove_if(greaterThan3);//delete elements satisfying given condition
    displayInt(fl4);


    /*Reversal*/
    cout<<"Reversing list fl4: ";
    fl4.reverse();
    displayInt(fl4);


    /*Splicing*/
    cout<<"Splicing fl4 with fl5: ";
    fl4.splice_after(fl4.before_begin(),fl5);//transfer elements from one list to another after given position
    displayInt(fl4);
    forward_list<int> fl6={10,11,12};
    cout<<"Splicing fl5: ";
    fl5.splice_after(fl5.before_begin(),fl6,fl6.begin());//splicing a list with single element of another list after given position
    displayInt(fl5);
    cout<<"Splicing fl1 with fl4in range(1,4): ";
    fl1.splice_after(fl1.begin(),fl4,fl4.before_begin(),fl4.end());//transfer elements in a given range(exclusive) from one list to another
    displayInt(fl1);


    return 0;
}

/* Operation        Complexity
   Insertion        O(1)
   Deletion         O(1)
   Traversal        O(n)
   Reversal         O(n)
   Splicing	    O(n)
*/

