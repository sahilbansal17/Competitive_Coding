/*
 
Defining the modified Fibonacci sequence as:
 
F(n) = F(n-1) + 2F(n-2) + 3F(n-3)
where, F(0) = 0, F(1) = 1, F(2) = 3
 
The following tasks have to complete for an entire score:
 
1. Write a function to return the nth modified Fibonacci number in less than O(n) time.
2. Write a function to print the first n modified Fibonacci numbers in O(n) time.
3. Clearly explain your solution, with proofs for how you arrived at the time complexities.
 
*/
 
#include<bits/stdc++.h>
using namespace std;
 
// METHOD - 1
// Time Complexity > O(n).
 
/*
int f(int n){
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else if(n==2)
        return 2;
    else
        return f(n-1) + 2 * f(n-2) + 3 * f(n-3);
}
*/
 
// METHOD - 2
// Time Complexity: O(n)
 
/*
int function(int n){
    int array[n];
    array[0] = 0;
    array[1] = 1;
    array[2] = 3;
    if(n >= 3){
        for(int i = 3; i <= n;i ++ ){
            array[i] = array[i-1] + 2*array[i-2] + 3*array[i-3];
        }
    }
    cout<<array[n];
}
*/
 
// METHOD - 3
// Time Complexity O(K^3 * log(n))

// Multiplying matrices takes 3 loops and thus K^3 complexity
// Modular exponentiation takes O(logn) time to find the matrix raised to the power n.

typedef vector<vector<int> > matrix;
 
matrix Exponentiation(matrix, int);
matrix MultiplyMatrix(matrix, matrix);
int FirstnModifiedFibonacci(int);
int Fibonacci(int n);

// Function to find the nth power of a given matrix
matrix Exponentiation(matrix arr, int n){
    if(n==1)
        return arr;
    if(n % 2 != 0)
        return MultiplyMatrix(arr, Exponentiation(arr, n-1));
    if(n%2 == 0)
        return MultiplyMatrix( Exponentiation(arr, n/2), Exponentiation(arr, n/2));
}

// Function to find the Multiplication of 2 matrices.
matrix MultiplyMatrix(matrix arr1, matrix arr2){
    matrix arr3(4, vector<int>(4));
    int i,j,k;
    for(i = 1; i <= 3; i ++){
        for(j = 1; j <= 3; j ++){
            for(k = 1; k <= 3; k ++){
                arr3[i][j] = (arr3[i][j] + arr1[i][k] * arr2[k][j]); 
            }
        }
    }
    return arr3;
}

// Function to find the modified_fibonacci number for a particular index n
int Fibonacci(int n){
    int i;
    // fun vector will have all the given constants c1,c2,c3.
    vector<int> fun(4);
    fun[1] = 1;
    fun[2] = 3;
    fun[3] = 5;
 
    // Transformation matrix to multiply with the fun Vector
    matrix Transformation(4, vector<int> (4)); 
 
    // Initializing the transformation matrix with known values and expected pattern
    // Last row contains the constants (c1,c2,c3) again.
    Transformation[1][1] = 0;
    Transformation[1][2] = 1;
    Transformation[1][3] = 0;
    Transformation[2][1] = 0;
    Transformation[2][2] = 0;
    Transformation[2][3] = 1;
    Transformation[3][1] = 3;
    Transformation[3][2] = 2;
    Transformation[3][3] = 1;
 
    if(n == 1)
            return 1;
    // calculating the n-1 th power of transformation matrix
    Transformation = Exponentiation(Transformation, n-1);
 
    int number=0;
    // Since only the first row of their multiplication will yield 
    for(i = 1;i <= 3;i ++){
        number = (number + Transformation[1][i] * fun[i]);
    }
 
    return number;
}

int FirstnModifiedFibonacci(int n){
    int array[n];
    array[0] = 0;
    array[1] = 1;
    array[2] = 3;
    for(int i = 0; i < 3; i ++){
        cout<<array[i]<<endl;
    }
    if(n >= 3){
        for(int i = 3; i <= n;i ++ ){
            array[i] = array[i-1] + 2*array[i-2] + 3*array[i-3];
            cout<<array[i]<<endl;
        }
    }
}

int main(void){
    int n;
    cout<<"Part-1: nth modified fibonacci number"<<endl;
    cout<<"Enter the Number"<<endl;
    cin>>n;
    cout<<Fibonacci(n)<<endl;

    cout<<"Part-2: first n modified fibonacci number"<<endl;
    // USE THIS IF n VALUE FOR PART-1 and PART-2 are not same.
    //cout<<"Enter the number till you want to find fibonacci numbers"
    //cin>>n;

    FirstnModifiedFibonacci(n);

    return 0;
}
