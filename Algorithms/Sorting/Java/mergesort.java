//MergeSort in java

import java.util.*;
public class mergesort
{
    //Driver function
    public static void main(String[] args) {

        Scanner sc=new Scanner(System.in);

        //Enter size of array.
        int n=sc.nextInt();

        int arr[]=new int[n];

        //Enter all the elements of the array.
        for(int i=0;i<arr.length;i++)
        {
            arr[i]=sc.nextInt();
        }       

        //Calling sort function with two indexes.
        int a[]=merge(arr,0,arr.length-1);

        //Printing the sorted array.
        for(int i=0;i<a.length;i++)
        {
            System.out.println(a[i]);
        }           
    }

    //Function processing sorting.
    static int[] merge(int a[],int l,int h)
    {
        //Calculatig the middle element.
        int m=l+(h-l)/2;

        //Base case
        if(l==h)
        {
            int arr[]=new int[1];
            arr[0]=a[l];
            return arr;
        }

        //Two Recursion statements : one sorting from l to middle,another sorting from middle+1 to h. 
        int larr[]=merge(a, l, m);
        int harr[]=merge(a, m+1, h);

        //A function calling statement to merge the above two sorted arrays accordingly.
        int merged[]=twomerge(larr,harr);

        //Returning the final sorted array.
        return merged;
    }

    //To merge the two sub sorted arrays.
    static int[] twomerge(int l[],int h[])
    {
        int i=0;
        int j=0;
        int k=0;

        //Declaring an array of length l.length+h.length
        int a[]=new int[l.length+h.length];

        //Adding the elements in the new array in sorted order.
        while(i<l.length&&j<h.length)
        {
            if(l[i]<=h[j])
           {
                a[k]=l[i];
            k++;
            i++;
           }
            else
           {
             a[k]=h[j];
            k++;
            j++;
           }
        }

        //To add the remaining elements if array l is shorter.
        if(i==l.length)
        {
            while(j<h.length)
            {
                a[k]=h[j];
                j++;
                k++;
            }
        }

        //To add the remaining elements if array h is shorter.
        else
        {
            while(i<l.length)
            {
                a[k]=l[i];
                i++;
                k++;
            }
        }

        //Returning the sorted array.
        return a;
    }
}

//Time Complexity : O(nlogn) => Two recursion calls both working for n/2,n/4,n/6.....
//also the time taken to merge the elements of both sub arrays.

//Space Complexity : O(n) => An extra memory(array) is used to merge the subarrays.(Does not sort in place)

