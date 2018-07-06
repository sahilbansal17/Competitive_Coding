#include<iostream>
//We need to include the set library to use the map and define various operations
#include<map>
// We need to include the iterator library which is used to iterate over the key and value of each pair
//These iterators iterate over the containers(i.e map in this case)
#include<iterator>
using namespace std;
bool checkEmpty(map<int,int> m){
    if(m.empty())
        return true;
    else
        return false;
}
int main(){
    // A map is container used to store the data in the form of key value pair
    map <int, int> m;
    int key , value, n;
    // insert elements into the map
    cout << "Enter the number of elements to be inserted into the map" << endl;
    cin >> n;
    cout << "Enter the elements to be inserted into the map" << endl;
    for(int i = 0;i < n;i++){
        cin >> key >> value;
        //creating a pair class to assign the elements entered by the user
        m.insert(pair <int, int> (key, value));
    }
    // printing the elements of the map
    cout << "The elements of the map are " << endl;
    map <int, int> :: iterator itr;
    for (itr = m.begin(); itr != m.end(); itr++)
    {
        cout << "key-->" << (*itr).first << " value--> " << (*itr).second << endl;
    }
    cout << endl;
    //returning the size and maximum size of the map
    cout << "The size of the map is " << m.size() << " and the maximum size is " << m.max_size() << endl;
    //checks whether the map is empty or not
    if(checkEmpty(m)){
        cout << "The map is empty" << endl;
    }
    else{
        cout << "The map is not empty" << endl;
    }
    int element_to_remove;
    cout << "Enter the key corresponding to element you want to remove" << endl;
    cin >> element_to_remove;
    m.erase(element_to_remove);
    cout << "After removing the remaining elements are " << endl;
    for (itr = m.begin(); itr != m.end(); itr++)
    {
        cout << "key-->" << (*itr).first << " value--> " << (*itr).second << endl;
    }
    cout << endl;
    // copying the elements from one map to another
    map <int, int> m1(m.begin(), m.end());

    // Print all elements of the map m1
    cout << "The elements of map m1 are" << endl;
    for (itr = m1.begin(); itr != m1.end(); itr++)
    {
        cout << "key-->" << (*itr).first << " value--> " << (*itr).second << endl;
    }
    cout << endl;
    return 0;
}
/*Time Complexity of insertion function is O(log n) since it is implemented as Red
Black Tree and the operations like to find the size ,to check whether the map is empty
or not takes constant time therefore time complexity = O(1) for all these operations and
Space Complexity = O(n) where n is the number of elements in case of map it will be 2*n
where n is for keys and remaining for values*/
