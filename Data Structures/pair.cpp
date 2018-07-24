// C++ STL Pair and the basic implementations on it
#include<iostream>
// we must include utility library to use pair class
// the significance of pair is to store two heterogeneous values and treat as one single entity
#include<utility>
using namespace std;
int main(){

    // creating a pair without initializing any value therefore it will take default value
    pair<int,int> p;
    cout << "The elements of the pair p are" << endl;
    cout << p.first << " " << p.second << endl;

    // creating pair with initializing the value
    char ch;
    int a;
    cout << "Enter one character and a integer" << endl;
    cin >> ch >> a;
    pair<char,int> p1(ch,a);
    cout << "The elements of the pair p1 are" << endl;
    cout << p1.first << " " << p1.second << endl;

    pair<char,char> p2('R','K');
    //making pair by copying value from another pair
    pair<char,char> p3(p2);
    cout << "The elements of the pair p3 are" << endl;
    cout << p3.first << " " << p3.second << endl;

    //creating pair by using make_pair function
    string s1,s2;
    pair<string,string> p4;
    cout << "Enter the two string values" << endl;
    cin >> s1 >> s2;
    p4 = make_pair(s1,s2);
    cout << "The elements of the pair p4 are" << endl;
    cout << p4.first << " " << p4.second << endl;

    // Basic operations on pair class
    int num1,num2;
    cout << "Enter the two integer elements for pair p5" << endl;
    cin >> num1 >> num2;
    pair<int, int>p5 = make_pair(num1, num2);
    cout << "Enter the two integer elements for pair p6" << endl;
    cin >> num1 >> num2;
    pair<int, int>p6 = make_pair(num1, num2);


    if(p5 == p6){
        cout << "Pair p5 and p6 are equal" << endl;
    }
    else if(p5 <= p6){
        cout << "Pair p5 is less than equal to p6" << endl;
    }
    else if(p5 >= p6){
        cout << "Pair p5 is greater than equal to p6" << endl;
    }

    return 0;
}
/*Time Complexity of all the operations in pair class is O(1)
Space Complexity directly depends on number of elements i.e O(n)
no matter whether the elements in the pair are heterogeneous or
homogeneous
*/
