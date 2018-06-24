//Name: Kumar Raju.B
//E-mail: bim2017008@iiita.ac.in
//TITLE: DYNAMIC ARRAY-VECTOR(STL)
#include<bits/stdc++.h>
using namespace std;
void displayArray( vector<int> v)
{
    vector<int> :: iterator it;
    for( it = v.begin() ; it!= v.end() ; ++it)
        cout<<*it<<" ";
    cout<<endl;
}
int main()
{     int i, n, value;
      vector<int> array;     
      cout<<"Input the number of elemnts you want to store in array:\n";
      cin>>n;
      cout<<"Enter the elements:\n";
      for( i = 0 ; i < n; ++i)
      {
          cin>>value;
          array.push_back(value);
      }

      // Syntax to append a value at the end of the array ,time complexity:O(1)
      array.push_back(10); 
      
      array[3] = 7; // Syntax to modify a value of the array
      
      // To find the number of elements in the array ,time complexity:O(1)
      cout<<"The size of the array is : "<<array.size()<<endl; 
      
      //The format to know the value at particular index is :(for ex. at 4) ,time complexity:O(1)
      cout<<"The value at index 4 is "<<array[4]<<endl;
      
      //Another alternative is array.at(position) ,time complexity:O(1)
      cout<<"The value at index 1 is "<<array.at(1)<<endl;
      
      //To traverse the array ,time complexity:O(n)
      cout<<"The array is:";
      for( i = 0 ; i < array.size(); ++i)
      {
          cout<<array[i]<<" ";
      }
      cout<<endl;
      
      //The displayArray() function created above is the recommended method of traversing the array ,time complexity:O(n)
      cout<<"The array is:";
      displayArray(array);
      
      //To traverse the array in reverse  ,time complexity:O(n)
      cout<<"The array in reverse is:";
      vector<int> :: reverse_iterator itr;
      for( itr = array.rbegin() ; itr!= array.rend() ; ++itr)
      {
          cout<<*itr<<" ";
      }
      cout<<endl;
      
      
      //To erase a single element (For example at position 0) ,time complexity:O(n)
      vector<int> :: iterator it1 = array.begin();
      array.erase(it1);
      cout<<"The array after erasing element at position 0 is:"; 
      display_array(array);
       
      //To erase elements in a range (For example between position 0 and position 2) ,time complexity:O(n)
      it1 = array.begin();
      vector<int> :: iterator it2 = array.begin();
      //This for loop is to point iterator it2 at position 2
      for( i = 0; i < 2; ++i)
        it2++;                      
      array.erase(it1, it2);
      cout<<"The array after erasing elements between position 0 and 2 is:";
      display_array(array);
      
      //To completely clear the array  ,time complexity:O(n)
      array.clear();
      
      //To check if the array is empty  ,time complexity:O(1)
      if( array.empty() == true)
        cout<<"Yes, the array is empty\n";
      else
        cout<<"No, the array is not empty\n";
   return 0;     
}
