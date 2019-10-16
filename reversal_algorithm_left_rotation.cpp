/* 
** Author :- Divyesh Srivastava
** Institute :- National Institute of Technology Meghalaya

            <----- Reversal Algorithm for Array Rotation  ----->
*/

 #include<iostream>
 #include<algorithm>
 
 using namespace std;
 
 int i,j;
 
 void left_rotation(int a[], int n, int d) // function to left rotate the array
 {
       reverse(a,a+d);  // reverse array from 0 to d-1
       reverse(a+d,a+n); // reverse array from d to n-1
       reverse(a,a+n); // finally reverse array from 0 to n-1
 }
 
  int main()
  {
      int n; // No. of elements in array
      
      cout<<"Enter no. of elements in array :";
      cin>>n;
      
      int a[n];
      
      for(i=0;i<n;i++)
       cin>>a[i];
       
       int d; // position to which u want to rotate the array
        cin>>d;
        
        d=d%n; // if d>n the to make it in range of n
       
        left_rotation(a,n,d); // left rotating the array by d position shift

        for(i=0;i<n;i++)
          cout<<a[i]<<" ";
         
  }
  /* Time Complexity :- O(n) */
