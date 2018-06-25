#include<iostream>
using namespace std;
//TIME COMPLEXITY: As the loop iterates through N elements once so it takes O(N) time.
void initialize(int A[] ,int n){ // initialize the array
    for(int i=0;i<n;i++)
        A[i] = i;
}

// returns true if x and y are connected, else returns false
//TIME COMPLEXITY: O(1) time needed as only a comparison need to be done
bool find(int A[],int x,int y){
    if(A[x] == A[y])
        return true;
    else
        return false;
}
//change all entries from A[x] to A[y]
//TIME COMPLEXITY: As the loop in the union function iterates through all the N elements
// for connecting two elements, performing this operation on N objects will take O(N^2) time
void unions(int A[],int n, int x, int y){
    int temp = A[x];
    for(int i=0;i<n;i++){
        if(A[x] == temp)    //Connect x to y and merge the components that comprise x and y
            A[i] = A[y];    //by replacing elements that have a value of A[ x ] with the value of A[ y ].
    }
}
// test drive main function
int main(){
    int x,y;
    cout << "Enter the no. of elements" << endl;
    int n;
    cin >> n;   //taking no. of elements in a set
    int A[n];   //making the set as first n whole numbers.
    initialize(A,n);    //Initially n subsets having one element each.
    int p;
    while(1){
        cout << "Press 1 for union or 2 for find and 3 for exit" << endl;
        cin >> p;
        if(p==3)
            break;  // user wants to exit
        cout << "Enter two elements:" << endl;
        cin >> x >> y;
        if(p==1){
            unions(A,n,x,y);    //Replace components that comprise the two objects x and y with their union
        }
        else
        {
            int v = find(A,x,y);    //Check whether the two objects A and B are in the same component
            if(v==0)
                cout  << "false" << endl;
            else
                cout << "true" << endl;
        }
    }
    return 0;
}
