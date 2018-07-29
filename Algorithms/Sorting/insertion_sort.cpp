#include<iostream>
#include<vector>
using namespace std;

/*
  Logic for insertion sort
  In this we divide the array not actually but logically, we consider two sub parts
  left part contains sorted while right part contains unsorted elements
  initially left part contains only one element i.e v[0] which is itself sorted
  we start from v[1] and for each element in unsorted part we place it into its proper
  position in sorted sub part
*/

void insertion_sort(vector<int> v, int n){
    // mechanism for insertion sort
    for(int i = 1;i < n;i++){
        int temp = v[i],j;
        for(j = i-1; j >=0; j--){
            if(v[j] > temp)
                v[j+1] = v[j];
            else
                break;
        }
        v[j+1] = temp;
    }
    // Printing the sorted elements
    cout << "The elements obtained after insertion sort are" << endl;
    for(int i = 0;i < n;i++)
        cout << v[i] << " ";
    cout << endl;
}

int main(){
    int n,num;
    vector<int> v;

    cout << "Enter the number of elements which you want to sort" << endl;
    cin >> n,num;
    cout << "Enter the elements into the array" << endl;
    // inserting elements into the vector
    for(int i = 0;i < n;i++){
        cin >> num;
        v.push_back(num);
    }
    // Calling the insertion sort
    insertion_sort(v,n);
    return 0;
}
/*
Time Complexity for insertion sort is O(n^2) since for every element we insert
into the sorted part we need to find its proper position to place
Space Complexity of insertion sort is O(n) because there is no auxiliary space used
*/
