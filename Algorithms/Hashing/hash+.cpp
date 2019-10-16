
#include <bits/stdc++.h> 
using namespace std; 
  

int countPairs(int arr1[], int arr2[],  
               int m, int n, int x) 
{ 
    int count = 0; 
      
   
    for (int i = 0; i < m; i++) 
        for (int j = 0; j < n; j++) 
  
            if ((arr1[i] + arr2[j]) == x)  
                count++; 
      
     
    return count; 
} 
  

int main() 
{ 
    int arr1[] = {1, 3, 5, 7}; 
    int arr2[] = {2, 3, 5, 8}; 
    int m = sizeof(arr1) / sizeof(arr1[0]); 
    int n = sizeof(arr2) / sizeof(arr2[0]); 
    int x = 10; 
    cout << "Count = "
         << countPairs(arr1, arr2, m, n, x); 
    return 0;      
}  
