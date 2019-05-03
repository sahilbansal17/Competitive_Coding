//NAME-Ananya Jain (Git username-Ananyajain721)
//email-ananyajain721@gmail.com


// Java program to impleament cycle sort
/*Cycle sort is an in-place, unstable sorting algorithm, a comparison sort that is theoretically optimal in terms of the total number of writes to the original array, unlike any other in-place sorting algorithm.

It is based on the idea that array to be sorted can be divided into cycles. Cycles can be visualized as a graph. We have n nodes and an edge directed from node i to node j if the element at i-th index must be present at j-th index in the sorted array.*/
import java.util.*;
import java.lang.*;
 
class CycleSort
{
// Function sort the array using Cycle sort
    public static void cycleSort (int arr[], int n)
    {
        // count number of memory writes
        int writes = 0;
 
        // traverse array elements and put it on the right place
        for (int cycle_start=0; cycle_start<n-1; cycle_start++)
        {
            // initialize item as starting point
            int item = arr[cycle_start];
 
            // Find position where we put the item. We basically
            // count all smaller elements on right side of item.
            int pos = cycle_start;
            for (int i = cycle_start+1; i<n; i++)
                if (arr[i] < item)
                    pos++;
 
            // If item is already in correct position
            if (pos == cycle_start)
                continue;
 
            // ignore all duplicate elements
            while (item == arr[pos])
                pos ++;
 
            // put the item to it's right position
            if (pos != cycle_start)
            {
                int temp = item;
                item = arr[pos];
                arr[pos] = temp;
                writes++;
            }
 
            // Rotate rest of the cycle
            while (pos != cycle_start)
            {
                pos = cycle_start;
 
                // Find position where we put the element
                for (int i = cycle_start+1; i<n; i++)
                    if (arr[i] < item)
                        pos += 1;
 
                // ignore all duplicate elements
                while (item == arr[pos])
                    pos += 1;
 
                // put the item to it's right position
                if (item != arr[pos])
                {
                    int temp = item;
                    item = arr[pos];
                    arr[pos] = temp;
                    writes++;
                }
            }
        }
    }
 
// The Main function
    public static void main(String[] args)
    {
        int arr[] = {1, 8, 3, 9, 10, 10, 2, 4 };
        int n = arr.length;
        cycleSort(arr, n) ;
 
        System.out.println("After sort : ");
        for (int i =0; i<n; i++)
            System.out.print(arr[i] + " ");
    }
}
/*
Time complexity

Worst, average and best case time complexity: O(n2)
Space complexity

Worst case: O(n) total
Auxillary space: O(1)*/
