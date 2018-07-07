#include<iostream>
//We need to include the set library to use the map and define various operations
#include<map>
// We need to include the iterator library which is used to iterate over the key and value of each pair
//These iterators iterate over the containers(i.e map in this case)
#include<iterator>
using namespace std;

int main(){
    // A map is container used to store the data in the form of key value pair
    map <string, int> m;
    string key ;
    int value, n;

    // insert elements into the map
    cout << "Enter the number of elements to be inserted into the map" << endl;
    cin >> n;
    cout << "Enter the elements to be inserted into the map" << endl;
    for(int i = 0;i < n;i++){
        cin >> key >> value;
        m[key] = value;
    }

    // printing the elements of the map
    cout << "The elements of the map are " << endl;
    map <string, int> :: iterator itr;
    for (itr = m.begin(); itr != m.end(); itr++){
        cout << "key-->" << (*itr).first << " value--> " << (*itr).second << endl;
    }
    cout << endl;

    //returning the size and maximum size of the map
    cout << "The size of the map is " << m.size() << " and the maximum size is " << m.max_size() << endl;

    //Checking if a particular element is present in the map or not
    string check_element_key;
    cout << "Enter the given key value to which you want to find value whether present or not" << endl;
    cin >> check_element_key;
    if(m.count(check_element_key)){
        cout << "The element is present" << endl;
    }
    else{
        cout << "The element is not present" << endl;
    }

    //find the iterator corresponding to an element
    string find_element_key;
    int pos = 1;
    cout << "Enter the key whose value's position you want to find in map" << endl;
    cin >> find_element_key;
    //find method returns an iterator
    map <string,int> :: iterator itr1 = m.find(find_element_key);
    for(itr = m.begin(); itr!= itr1; itr++)
         pos ++;
    cout << "The position of the element is " << pos << endl;

    //checks whether the map is empty or not
    if(m.empty()){
        cout << "The map is empty" << endl;
    }
    else{
        cout << "The map is not empty" << endl;
    }

    //Removing an element from the map
    string key_element;
    cout << "Enter the key corresponding to element you want to remove" << endl;
    cin >> key_element;
    m.erase(key_element);
    cout << "After removing the remaining elements are " << endl;
    for (itr = m.begin(); itr != m.end(); itr++){
        cout << "key-->" << (*itr).first << " value--> " << (*itr).second << endl;
    }
    cout << endl;

    // copying the elements from one map to another
    map <string, int> m1(m.begin(), m.end());

    // Print all elements of the map m1
    cout << "The elements of map m1 are" << endl;
    for (itr = m1.begin(); itr != m1.end(); itr++){
        cout << "key-->" << (*itr).first << " value--> " << (*itr).second << endl;
    }
    cout << endl;
    return 0;
}
/*Time Complexity of insertion function is O(log n) since it is implemented as Red
Black Tree and the operations like to find the size ,to check whether the map is empty
or not takes constant time therefore time complexity = O(1) for all these operations

Space Complexity = O(n) where n is the number of elements in case of map it will be 2*n
where n is for keys and remaining for values*/
