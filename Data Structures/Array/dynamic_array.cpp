/*
   DYNAMIC ARRAYS : VECTOR (STL)
*/
#include<bits/stdc++.h>
using namespace std;
void display_array( vector<int> v)
{
    vector<int> :: iterator it;
    for( it = v.begin() ; it!= v.end() ; ++it)
        cout<<*it<<" ";

    cout<<endl;
}

int main()
{     int i;
      vector<int> array = {1,2,3,4};   //The syntax for intializing a dynamic array using vector(STL)
      
      array.push_back(10); // Syntax to append a value at the end of the array
      
      array[3] = 7; // Syntax to modify a value of the array
      
      // To find the number of elements in the array
      cout<<"The size of the array is : "<<array.size()<<endl; 
      
      //The format to know the value at particular index is :(for ex. at 4)
      cout<<"The value at index 4 is "<<array[4]<<endl;
      
      //Another alternative is array.at(position)
      cout<<"The value at index 1 is "<<array.at(1)<<endl;
      
      //To traverse the array
      cout<<"The array is:";
      for( i = 0 ; i < array.size(); ++i)
      {
          cout<<array[i]<<" ";
      }
      cout<<endl;
      
      //The display_array() function created above is the recommended method of traversing the array
      cout<<"The array is:";
      display_array(array);
      
      //To traverse the array in reverse
      cout<<"The array in reverse is:";
      vector<int> :: reverse_iterator itr;
      for( itr = array.rbegin() ; itr!= array.rend() ; ++itr)
      {
          cout<<*itr<<" ";
      }
      cout<<endl;
      
      
      //To erase a single element (For example at position 0)
      vector<int> :: iterator it1 = array.begin();
      array.erase(it1);
      cout<<"The array after erasing element at position 0 is:"; 
      display_array(array);
       
      //To erase elements in a range (For example between position 0 and position 2)
      it1 = array.begin();
      vector<int> :: iterator it2 = array.begin();
      for( i = 0; i < 2; ++i)
        it2++;                 //This for loop is to point iterator it2 at position 2
      array.erase(it1, it2);
      cout<<"The array after erasing elements between position 0 and 2 is:";
      display_array(array);
      
      //To completely clear the array
      array.clear();
      
      //To check if the array is empty
      if( array.empty() == true)
        cout<<"Yes, the array is empty\n";
      else
        cout<<"No, the array is not empty\n";
    
     
   return 0;     
}
