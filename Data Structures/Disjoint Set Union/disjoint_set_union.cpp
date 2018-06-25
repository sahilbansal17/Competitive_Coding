#include<iostream>
using namespace std;

void initialise(int A[] ,int n){ // initialise the array
    for(int i=0;i<n;i++)
        A[i] = i;
}

// returns true if x and y are connected, else retuens false
bool find(int A[],int x,int y){
    if(A[x] == A[y])
        return true;
    else
        return false;
}
//change all entries from A[x] to A[y]
void unions(int A[],int n, int x, int y){
    int temp = A[x];
    for(int i=0;i<n;i++){
        if(A[x] == temp)
            A[i] = A[y];
    }
}

int main(){
    int x,y;
    cout << "Enter the no. of components" << endl;
    int n;
    cin >> n;
    int A[n];
    initialise(A,n);
    int p;
    while(1){
        cout << "Press 1 for union or 2 for find and 3 for exit" << endl;
        cin >> p;
        if(p==3)
            break;
        cout << "Enter two components:" << endl;
        cin >> x >> y;
        if(p==1){
            unions(A,n,x,y);
        }
        else
        {
            int v = find(A,x,y);
            if(v==0)
                cout  << "false" << endl;
            else
                cout << "true" << endl;
        }
    }

}
