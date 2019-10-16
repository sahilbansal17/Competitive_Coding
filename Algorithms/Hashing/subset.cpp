// C++ program to find whether an array 
// is subset of another array 
#include<bits/stdc++.h> 
  
/* Return 1 if arr2[] is a subset of  
arr1[] */
bool isSubset(int arr1[], int arr2[],  
                        int m, int n) 
{ 
    int i = 0; 
    int j = 0; 
    for (i = 0; i < n; i++) 
    { 
        for (j = 0; j < m; j++) 
        { 
            if(arr2[i] == arr1[j]) 
                break; 
        } 
          
        /* If the above inner loop was 
        not broken at all then arr2[i] 
        is not present in arr1[] */
        if (j == m) 
            return 0; 
    } 
      
    /* If we reach here then all 
    elements of arr2[] are present 
    in arr1[] */
    return 1; 
} 
  
// Driver code 
int main() 
{ 
    int arr1[] = {11, 1, 13, 21, 3, 7}; 
    int arr2[] = {11, 3, 7, 1}; 
  
    int m = sizeof(arr1)/sizeof(arr1[0]); 
    int n = sizeof(arr2)/sizeof(arr2[0]); 
  
    if(isSubset(arr1, arr2, m, n)) 
        printf("arr2[] is subset of arr1[] "); 
    else
        printf("arr2[] is not a subset of arr1[]");      
  
    getchar(); 
    return 0; 
} 
