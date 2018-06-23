/*

Amortized Analysis is used for algorithms where an occasional operation
is very slow, but most of the other operations are faster. In Amortized
Analysis, we analyze a sequence of operations and guarantee a worst case
average time which is lower than the worst case time of a particular
expensive operation.

The worst case cost of an insertion is O(n), n being length of the array.
Hence for n insertion the cost is O(n^2). But using the array doubling
technique we can prove that the amortized cost is O(1).

Element No: 1 2 3 4 5 6 7 8 9 10 ...
Array Size: 1 2 4 4 8 8 8 8 16 16 ...
Cost:       1 2 3 1 5 1 1 1 9 1 ...

Amortized cost = (1+2+3+5+1+1+9+1 ...)/n
                = [(1+1+1+1+...)+(1+2+4..)]/n
                <= [n+2n]/n
                <= 3
Hence Amortized cost = O(1)
*/

#include <iostream>
using namespace std;

// A function to print an array
void print_array (int arr[], int length){
    
    cout<<"The array is: ";
    for (int i = 0; i < length; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    
}

/* A function to double the array size, it takes the array to be 
    doubled and returns the length of the doubled array */
int array_doubling(int array[], int length) {
    
    int new_length = length * 2;
    try{
        int *new_array = new int[new_length]; //allocate memory
        // Copy the existing elements
        for (int i=0; i<length; i++){
            new_array[i] = array[i];
        }
        array = new_array;
        delete new_array;
    }
    catch (std::bad_alloc& ba){
        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
        exit(1);
    }
    return new_length;
}

int main() {
    
    int arr[1];
    int index = 0, length = 1, number, cur_length = 0;

    while (1){
        cout<<"Enter an integer (0 to end): ";
        cin>>number;
        if (number == 0)
            break;
        cur_length ++;
        if (cur_length > length){
            length = array_doubling (arr, length);
        }
        arr[index] = number;
        index++;
        print_array (arr, index);
    }
    print_array (arr, index);
	return 0;
}
