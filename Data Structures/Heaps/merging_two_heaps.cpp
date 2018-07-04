#include<iostream>
#include<vector>
using namespace std;

class MinHeap{
     void heapify(int index){
        //finding the index of left and right child respectively for comparison
        int left_child = 2 * index;
        int right_child = left_child +1;
        //Setting min_index to first index
        int min_index = index;
        //Checking whether left or right child has a value which is less than value at current min_index
        if(left_child < v3.size() && v3[left_child] < v3[min_index] ){
            min_index = left_child;
        }
        if(right_child < v3.size() && v3[right_child] < v3[min_index]){
            min_index = right_child;
        }
        //Checking whether element at index index <=={(note: no typo} contains the minimum element or not
        if(min_index != index){
            swap(v3[min_index],v3[index]);
            heapify(min_index);
        }
    }
    public:
        vector<int> v1; //to store the elements of first heap
        vector<int> v2; //to store the elements of second heap
        vector<int> v3; //to store the elements of heap after merging of two heaps
        //Constructor
        MinHeap(){
            //Setting v[0] to any garbage considering only positive elements inside heap
            v1.push_back(-1);
            v2.push_back(-1);
            v3.push_back(-1);
        }
         //Buidling the heap
        void buildHeap(int n){
            int heap_size = n;
            for(int i = heap_size/2;i > 1;i--){
                heapify(i);
            }
        }
        void insertToFirstHeap(int data){
            v1.push_back(data);
            int index = v1.size() -1;
            int parent = index/2;

            while(index > 1 && v1[index] < v1[parent]){
                swap(v1[index],v1[parent]);
                index = parent;
                parent = index /2;
            }
        }
        void insertToSecondHeap(int data){
            v2.push_back(data);
            int index = v2.size() -1;
            int parent = index/2;

            while(index > 1 && v2[index] < v2[parent]){
                swap(v2[index],v2[parent]);
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
        h.insertToFirstHeap(num);
        h.v3.push_back(num); //copying items from first array
    }
    cout << "The elements of the first heap are" << endl;
    for(int i = 1;i < h.v1.size() ;i++){
        cout << h.v1[i] << " ";
    }
    cout << endl;

    cout << "Enter the number of elements of the second heap" << endl;
    cin >> size_arr_two;
    cout << "Enter the elements to be inserted into the second heap" << endl;
    for(int i = 0;i < size_arr_two;i++){
        cin >> num;
        h.insertToSecondHeap(num);
        h.v3.push_back(num); //copying the items from second array
    }
    cout << "The elements of the second heap are" << endl;
    for(int i = 1; i < h.v2.size() ;i++){
        cout << h.v2[i] << " ";
    }
    cout << endl;

    //calling the buildHeap method to build the heap
    h.buildHeap(h.v3.size());
    cout << "After merging the elements of resulting heap are" << endl;
    for(int i = 1; i < h.v3.size();i++){
         cout << h.v3[i] << " ";
    }
    cout << endl;
    return 0;
}
