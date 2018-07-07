#include<iostream>
//We need to include the set library to use the set and define various operations
#include<set>
// We need to include the iterator library which is used to iterate over the elements of the set
//These iterators iterate over the containers(i.e set in this case)
#include<iterator>
using namespace std;

int main(){
    //Sets are containers that store unique elements following a specific order.
    //Creating a store to store integer values
    set <int> s;
    int n,num;
    // insert elements into the set
    cout << "Enter the number of elements to be inserted into the set" << endl;
    cin >> n;
    cout << "Enter the elements to be inserted into the set" << endl;
    for(int i = 0;i < n;i++){
        cin >> num;
        s.insert(num);
    }

    //initializing an iterator of the set
    set <int> :: iterator itr;

    // printing set elements
    cout << "The elements of the set are " << endl;
    for (itr = s.begin(); itr != s.end(); itr++){
        cout << *itr << " ";
    }
    cout << endl;
    
    //returning the size of the set
    cout << "The size of the set is " << s.size() << endl;

    //Checking if a particular element is present in the list or not
    int check_element;
    cout << "Enter the element which you want to check whether present or not" << endl;
    cin >> check_element;
    if(s.count(check_element)){
        cout << "The element is present" << endl;
    }
    else{
        cout << "The element is not present" << endl;
    }

    //check whether we can insert duplicate element in the set or not
    int dup_element;
    cout << "Enter any element which is already present in set" << endl;
    cin >> dup_element;
    s.insert(dup_element);
    cout << "After inserting duplicate element the elements of set are" << endl;
    for (itr = s.begin(); itr != s.end(); itr++){
        cout << *itr << " ";
    }
    cout << endl;

    //find the iterator corresponding to an element
    int find_element,pos = 1;
    cout << "Enter the element whose position you want to find in set" << endl;
    cin >> find_element;
    //find method returns an iterator
    set<int> :: iterator itr1 = s.find(find_element);
    for(itr = s.begin(); itr!= itr1; itr++)
         pos ++;
    cout << "The position of the element is " << pos << endl;

    //removing an element from the set
    int element_to_delete;
    cout << "Enter the element from the set which you want to delete" << endl;
    cin >> element_to_delete;
    s.erase(element_to_delete);

    cout << "After removing the elements of the set are: " << endl;
    for(itr = s.begin(); itr != s.end() ;itr ++){
        cout << *itr << " ";
    }
    cout << endl;

    // copying all the elements from s to s1
    set <int> s1(s.begin(), s.end());
    // print all elements of the set s1
    cout << "The elements of set s1 are: " << endl;
    for (itr = s1.begin(); itr != s1.end(); itr++){
        cout << *itr << " ";
    }
    cout << endl;

    //If we want to specify the order of insertion of elements we can declare set as
    set< int , greater<int> >s2;
    cout << "Enter the elements to be inserted into ordered set" << endl;
    cin >> n;
    cout << "Enter elements into an ordered set" << endl;
    for(int i = 0; i < n; i++){
        cin >> num;
        s2.insert(num);
    }
    // print all elements of the ordered set s2
    cout << "The elements of set s2 are: " << endl;
    for (itr = s2.begin(); itr != s2.end(); itr++){
        cout << *itr << " ";
    }
    cout << endl;

    //check whether the set is empty or not
    if(s.empty()){
        cout << "The input set is empty" << endl;
    }
    else{
        cout << "The input set is not empty" << endl;
    }
    return 0;
}
/*Time Complexity of insertion function is O(log n) since set are implemented as Red Black Tree
If we are building a ordered set therefore red black is opted as best choice and the operations
like to find the size ,to check whether the set is empty or not takes constant time therefore
time complexity = O(1) for all these operations

Space Complexity = O(n) where n is the number of elements*/
