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
Time Complexity for insertion sort is O(n^2) in the worst case since 
for every element we insert into the sorted part we need to find its
proper position to place
For best case time complexity is O(n) (best case is when all the 
elements are in sorted order by default) because we do not need to 
make additional swaps
For the average case the time complexity is O(n^2) because in avg case
we can consider half of elements need no shifting as they are already
sorted and remaining half require to move to their correct position.
Thus time required would be half of that of worst case.But we don't 
consider constants in analysis of time complexity.Therefore the result
is same as that of worst case

Space Complexity of insertion sort is O(n) because there is no auxiliary
space used
*/
