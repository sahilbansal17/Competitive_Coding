#include<iostream>
#include<vector>
using namespace std;

class MinHeap{
    public:
        vector<int> v;
        //Constructor
        MinHeap(){
            //Setting v[0] to any garbage considering only positive elements inside heap
            v.push_back(-1);
        }
        //building the heap
        void buildHeap(int data){
            v.push_back(data);
            int index = v.size() -1;
            int parent = index/2;

            while(index > 1 && v[index] < v[parent]){
                swap(v[index],v[parent]);
                index = parent;
                parent = index /2;
            }
        }
};

int main(){
    int size_arr_one,size_arr_two,num;
    cout << "Enter the number of elements of the first heap" << endl;
    cin >> size_arr_one;
    //int arr_one [] = {1,4,3,2,6,0,10,12};
    //int arr_two [] = {9,7,5,8};
    //Creating a heap into memory
    MinHeap h;
    //inseting the elements and thus building the heap
    cout << "Enter the elements to be inserted into the first heap" << endl;
    for(int i = 0;i < size_arr_one;i++){
        cin >> num;
        h.buildHeap(num);
    }
    cout << "The elements of the first heap are" << endl;
    for(int i = 1;i < h.v.size() ;i++){
        cout << h.v[i] << " ";
    }
    cout << endl;
    cout << "Enter the number of elements of the second heap" << endl;
    cin >> size_arr_two;
    cout << "Enter the elements to be inserted into the second heap" << endl;
    for(int i = 0;i < size_arr_two;i++){
        cin >> num;
        h.buildHeap(num);
    }
    cout << "The elements of the second heap are" << endl;
    for(int i = size_arr_one+1; i < h.v.size() ;i++){
        cout << h.v[i] << " ";
    }
    cout << endl;
    cout << "After merging the elements of resulting heap are" << endl;
    //Printing the resultant heap
    for(int i = 1;i < h.v.size() ;i++){
        cout << h.v[i] << " ";
    }
    cout << endl;
    return 0;
}
