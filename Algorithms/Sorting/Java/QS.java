/* 
AUTHOR: Bharati Subramanian
EMAIL:  bharatisharada@gmail.com
*/

//This program sorts the given input array using Quick sort

//importing scanner class to read console input
import java.util.Scanner;

public class QS 
{
    public static void main(String[] args) 
    {
        Scanner s = new Scanner(System.in);
        QS q = new QS();
        //a[]: An integer array to stores values to be sorted
        //n: number of elements in the array
        int n,a[];
        n = s.nextInt();
        a = new int[n+1];
        for(int i= 0; i<n; i++)
        {
            a[i] = s.nextInt();
        }
        a[n]=+999999;
        
        q.quickSort(a,0,n-1);
        
        //printing the sorted array
        for(int k=0; k<n; k++)
        {
                System.out.print(a[k]+ " ");
        }
        System.out.println();
    }
    void quickSort(int[] a, int left, int right)
    {
        //left: starting index (initially 1)
        //right: ending index (initially n)
        
        if(left<right)
        {
            /*
                pivot element: the first element is chosen as the pivot element
                partitioning the array into 2 halves around the pivot element 
                such that the value of elements appearing before the pivot is less than the value of pivot
                and those appearing after the pivot are greater than the pivot.
            */
            
            int pivot = partition(a, left, right+1);
            
            /*
                recursively invoking quickSor(a,left,right) to find the pivot element in each half of the array
                which eventually sorts the array
            */
            quickSort(a, left, pivot-1);
            quickSort(a, pivot+1, right);
        }
    }
    
    int partition(int[] a, int left, int right)
    {
        //finding the correct position of the pivot element and returns its position j
        int pivot = a[left];
        int i=left, j= right;
        
        do
        {
            do
            {
                i= i+1;
            }
            while( a[i]<= pivot && i<right);
            
            do
            {
                j=j-1;
            }while(a[j]>= pivot && j>left);
            
            if(i<j)
            {
                int temp = a[i];
                a[i]=a[j];
                a[j] = temp;
            }
            
        }while(i<=j);
        
        a[left] = a[j];
        a[j] = pivot;
        return j;
    }
}


/*

Worst Case Time complexity analysis of Quick Sort: O(n^2)
    In the worst case, the pivot element chosen each time would be either the smallest or the largest element among the array of values.
    The first call to quicksort(a,0,n) would take nc for some conatant c. The elements now will be partitioned such that one half has 0 
    elements and the second half has n-1 elements. Hence this recursive call would take c(n-1) for some constant c.
    Proceeding this way we arrive at the following:
                cn + c(n-1)+ c(n-2)+ ..... + 2c
              = c(n+ (n-1)+ (n-2) + .... + 2)
              = c((n+1)*n/2)
              = O(n^2)       
*/
