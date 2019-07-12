//Selection Sort in java

import java.util.*;
class SelectionSort {

    public static void main(String[] args) {
          Scanner sc=new Scanner(System.in);

          //Enter size of array.
          int n=sc.nextInt();

          int[] arr = new int[n];
          //Enter the array elements.
          for(int i=0;i<n;i++)
          arr[i]=sc.nextInt();
          //Function call implementing sorting.
          sort(arr);

          System.out.println(Arrays.toString(arr));
          sc.close();
      }
  
     
      public static void sort(int[] arr) {
          for (int i = 0; i < arr.length; i++) {
              
              for (int j = i + 1; j < arr.length; j++) {
                
                  //Swaping the elements if the value at index j is less than at index i.
                  if (arr[j] < arr[i]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                  }
              }
              
          }
      }       
      
  }
  //Time Complexity : O(n^2) => Two for loops are used itering till the length of the array.
  //Space Complexity : O(1) => NNo extra memory is used.