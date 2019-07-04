// Insertion Sort 

//Insertion Sort in Java

import java.util.*;

class insert { 

 //driver method
 public static void main(String args[])
    { 
         Scanner sc=new Scanner(System.in);

         //Enter the size of array.
         int n=sc.nextInt();

         int arr[]=new int[n];
       
         //Enter the array elements.
         for(int i=0;i<n;i++)
           arr[i]=sc.nextInt();
        
        
         //Creating an object of the class
         insert obj1 = new insert(); 

         //Calling the function through call by reference
         obj1.sorting(arr); 

         //Printing the array elements
         for (int i = 0; i < arr.length; i++) 
            System.out.print(arr[i] + " "); 
  
         
    } 
    
    //The called function sorting the array
    void sorting(int a[]) 
    { 
       
        int j=0;
        for (int i = 1; i < a.length; i++) { 
            
            j = i - 1; 

            //Storing the data of the current index of array
            int s=a[i];
           
           //Shifting  the elements to the right till we encounter a number smaller than s or at the starting point.
            while (j >= 0 && a[j] > s) { 
                a[j + 1] = a[j]; 
                j = j - 1; 
            } 
            //adding s to the right position
            a[j + 1] = s; 
        } 
    } 
  
 }
// Time complexity :O(n^2)
//As we have a nested loop: for loop running for n times.(size of the array)
//The upper head of the while loop is also n times when the smallest element is at the last index,so the time taken to execute the program can never reach beyond ^2.

//Space complexity : O(1) This solution takes O(1) extra space.
