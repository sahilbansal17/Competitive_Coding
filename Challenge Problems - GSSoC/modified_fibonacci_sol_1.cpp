#include <bits/stdc++.h>
using namespace std;
/*
Defining the modified Fibonacci sequence as:
F(n) = F(n-1) + 2F(n-2) + 3F(n-3)
where, F(0) = 0, F(1) = 1, F(2) = 3
The following tasks have to complete for an entire score:
1. Write a function to return the nth modified Fibonacci number in less than O(n) time.
2. Write a function to print the first n modified Fibonacci numbers in O(n) time.
3. Clearly explain your solution, with proofs for how you arrived at the time complexities.
*/
/* Matrix exponentiation Time complexity of the process is O(log n)*/
 /* Concept used to optimize the calcluation of the power:
    pow(a,n) = pow(a,n/2)*pow(a,n/2) if n is even
    pow(a,n) = pow(a,(n-1)/2*pow(a,(n-1)/2)*a if n is odd
    This allows us to reduce the time complexity to O(log n)*/
/* 
Time complexity proof:
 T(n) = T(n/2) + 1 It takes unit time for multiplication
now note that 1 == pow(n,log 1)
therefore by master theorem your time complexity is O(log n)
An alternative interpretaion can be made by considering a recursion tree. Height of such a tree is log(n) and 
every operation will take o(1) time. Therefore, time complexity is O(log n)
the idea is an extension of the standard fibonacci problem statement
initial equation : {{f(n)},{f(n-1)},{f(n-2)}} = A *{{f(n -1 )},{f(n-2)},{f(n-3)}} 
our objective is to find A
Solving the eqations formed using the recurrence relation given in step 1 for f(n) along with comparing for f(n-1) and f(n-2),
 we obtain fibonacci matrix relation -> A = {{1,2,3},{1,0,0},{0,1,0}}
By recursively solving the equation we achieve -> {{f(n)},{f(n-1)},{f(n-2)}} = power(A,n)*{{f(2)},{f(1)},{f(0)}} where power(A,n) follows rules of matrix multiplication */
void aiply(int a[3][3], int b[3][3])// matrix multiplication
{
    int mul[3][3];
    for(int i = 0; i < 3;i++)
    {
        for(int j = 0; j < 3; j++)
        {
            mul[i][j] = 0;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            
            for (int k = 0; k < 3; k++)
                mul[i][j] += a[i][k]*b[k][j];
        }
    }
 
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            a[i][j] = mul[i][j]; // updating matrix 
}
 int calculate_a(int a[3][3], int x) // calculate the nth modified fibonacci for n>=3
{
   int b[3][3] = {{1,2,3},{1,0,0},{0,1,0}}; // Initialising the 3*3 matrix 
   if(x==1)
   {
    return (3 * a[0][0] + a[0][1]);
   }
	calculate_a(a,x/2);
	aiply(a,a);
	if((x)%2 != 0 )
	{
		aiply(a,b);
	}
   
return (3 * a[0][0] + a[0][1]);
}
/*F(n) = F(n-1) + 2F(n-2) + 3F(n-3)
Running one loop only therefore time complexity is O(n) for print_series*/
void print_series(int n)
{
    int f[n]; // n fibonacci number sequence
    f[0] = 0, f[1] = 1,f[2] = 3;
   for(int i = 0; i < 3; i ++)
   {
        cout<<f[i]<<endl;
    }
    if(n >= 3){
        for(int i = 3; i <= n;i ++ ){
            f[i] = f[i-1] + 2*f[i-2] + 3*f[i-3];
            cout<<"F(" << i << ") = " << f[i]<<endl;
        }
    }
}
int nthnumber(int n)// responsible for finding the nth number
{
	int base[3][1];
    base[0][0] = 3;
    base[1][0] = 1;
    base[2][0] = 0;
	int a[3][3];
    // Initialising the 3*3 matrix
	a[0][0] = 1; a[0][1] = 2;
    a[0][2] = 3;
    a[1][0] = 1;
    a[1][1] = 0;
    a[1][2] = 0;
    a[2][0] = 0;
    a[2][1] = 1;
    a[2][2] = 0;
        if(n==1)
	{
		return base[1][0];
	}
	else if( n == 2)
	{
   
		return base[0][0];
	}
	else if(n == 0)
	{
		return base[2][0];
	}
    else
    {
        return calculate_a(a,n-2);

    }
	
}
int main()
{
	cout << "enter the value of n";//prompt
	int n;
	 cin >> n;
	int x = nthnumber(n);
    print_series(n); 
    cout << "F("<<n << ") = " << x << endl;
    return 0;
}
