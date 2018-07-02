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
        if(left_child < v.size() && v[left_child] < v[min_index] ){
            min_index = left_child;
        }
        if(right_child < v.size() && v[right_child] < v[min_index]){
            min_index = right_child;
        }
        //Checking whether element at index index <=={(note: no typo} contains the minimum element or not
        if(min_index != index){
            swap(v[min_index],v[index]);
            heapify(min_index);
        }
    }
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
                int index = v.size()-1;
                int parent = index/2;

                while(index > 1 && v[index] < v[parent]){
                   swap(v[index],v[parent]);
                   index = parent;
                   parent = parent/2;
                }
            }
            //returning the mjnimum element from the heap
            int getMin(){
                return v[1];
            }
            //extracting the minimum element from the heap
            void extractMin(){
                int last = v.size() -1;
                swap(v[1],v[last]);
                v.pop_back();
                heapify(1);
            }
            //Checking whether the heap is empty or not
            bool isEmpty(){
                return (v.size() == 1) ? 1:0;
            }
};

int main(){

    int arr[100],num,n;

    cout << "Enter the number of elements to be inserted to the heap" << endl;
    cin >> n;
    //Creating a heap into memory
    MinHeap h;
    cout << "Enter the elements to be inserted into the heap" << endl;
    //inseting the elements and thus building the heap
    for(int i = 0;i < n ;i++){
        cin >> num;
        h.buildHeap(num);
    }
    //Printing the resultant heap
    cout << "The elements of heap are" << endl;
    for(int i = 1;i < h.v.size() ;i++){
        cout << h.v[i] << " ";
    }
    cout << endl;

    cout << "The minimum element of the heap are" << endl;
    cout << h.getMin() << endl;

    //Extracting the mimimum element from the heap
    h.extractMin();
    cout << "After extracting the minimum element the resulting heap is" << endl;
    for(int i = 1;i < h.v.size() ;i++){
        cout << h.v[i] << " ";
    }

    return 0;
}
/*
        Time Complexity of various operations in the heap

        Let us consider the worst case complexity.In these the element which is a root is maximum among
        all elements so it goes down the branch till the leaf.Therefore time complexity is O(log n) which
        as same as traversing through a branch in a tree

        Time Complexity in building a heap
        The worst case comes when the data occupies top of the heap or root node or first element  of the vector
        Then complexity is same as traversing a branch therefore time complexity is O(log n)

        Time complexity of returning minimum element is O(1)

        Time Complexity for checking whether the heap is empty or not is O(1)

        
        Space complexity for building the heap is described as
        total space for n elements to be inserted + plus some temporary variables required
        in building up the heap
        Therefore overall space complexity depends upon n that is O(n)
*/

