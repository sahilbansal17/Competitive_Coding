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
//The iterator in the below for loop is decremented because after erasing, the next element occupies the current position
vector<int> delEvenValues(vector<int> v)
{
  vector<int> :: iterator it;
  for( it = v.begin() ; it!= v.end() ; ++it)
    {
        if((*it)%2 == 0)
        {
          v.erase(it);
          it--;
        }
    }
    return v;
}
int main()
{     int i, n, value, position, position1, position2;
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

      // Syntax to modify a value of the array
      cout<<"Enter the index at which value is to be changed: \n";
      cin>>position;
      cout<<"Enter the value:\n";
      cin>>value;
      array[position] = value;
      // To find the number of elements in the array ,time complexity:O(1)
      cout<<"The size of the array is : "<<array.size()<<endl;

      //The format to know the value at particular index ,time complexity:O(1)
      cout<<"Enter the index at which you want to know the value:\n";
      cin>>position;
      cout<<"The value at index "<<position<<" is "<<array[position]<<endl;

      //Another alternative is array.at(position) ,time complexity:O(1)
      cout<<"The value at index "<<position<<" is "<<array.at(position)<<endl;

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

      //To erase a single element ,time complexity:O(n)
      cout<<"Enter the index at which value is to erased: \n";
      cin>>position;
      vector<int> :: iterator it1 = array.begin();
      //This for loop is to point iterator it1 at required position
      for(int i = 0; i < position ; ++i)
          it1++;
      array.erase(it1);
      cout<<"The array after erasing element at required position is:";
      displayArray(array);

      //To erase elements in a range ,time complexity:O(n)
      it1 = array.begin();
      vector<int> :: iterator it2 = array.begin();
      cout<<"Enter the indexes between which values are to erased: \n";
      cin>>position1>>position2;
      for(int i = 0; i < position1 ; ++i)
        it1++;
      for( i = 0; i < position2; ++i)
        it2++;
      array.erase(it1, it2);
      cout<<"The array after erasing elements between the asked positions is:";
      displayArray(array);

      //Function to delete even valued elements, time coplexity = O(n^2)
      array = delEvenValues(array);
      cout<<"The array after erasing even valued elements is:";
      displayArray(array);

      //To completely clear the array  ,time complexity:O(n)
      array.clear();

      //To check if the array is empty  ,time complexity:O(1)
      if( array.empty() == true)
        cout<<"Yes, the array is empty\n";
      else
        cout<<"No, the array is not empty\n";
   return 0;
}
