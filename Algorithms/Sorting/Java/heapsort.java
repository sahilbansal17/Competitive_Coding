import java.util.Scanner;

public class heapsort 
{   public  static void heapify(int[] a, int n, int pi)  
    {  
        //pi is the current index
        int largest = pi; 

        //l is the index of left child of pi when assumed in a binary tree.     
        int l = 2*pi + 1;   

        //r is the index of right child of pi when assumed in a binary tree.
        int r = 2*pi + 2; 

        if (l< n && a[l] > a[largest])  
        largest = l;  
        
        if (r < n && a[r] > a[largest])  
        largest = r;  
        
        //If element at pi is not the largest,swaping the elements.
        //Again calling heapify to place the largest correctly in the heap.
        if (largest != pi)  
        {  
            int t = a[pi];  
            a[pi]= a[largest];   
            a[largest] = t;  
            heapify(a, n, largest);  
        }  
    }  
      
    public static void sort(int[] arr, int len)  
    {    
        //Creating a max-heap by calling heapify.
        for (int i = len / 2 - 1; i >= 0; i--)  
        heapify(arr, len, i); 

        //Swaping the first element with the last element of the heap.
        //Thus largest element is placed at the last position.
        //(Heap till position i is taken into consideration at each step.)
        //Again calling heapify function to place the element at 0th position correctly in the heap.
        for (int i=len-1; i>=0; i--)  
        {  
            int temp = arr[0];  
            arr[0]= arr[i];   
            arr[i] = temp;  
            heapify(arr, i, 0);  
        }  
    }  
      
    public static void main(String []args)  
    {  
        Scanner sc=new Scanner(System.in);

        //Enter no. of elements
        int n=sc.nextInt();

        int a[]=new int[n];

        //Enter the elements
        for(int i=0;i<n;i++)
        a[i]=sc.nextInt();

        //Function to sort the elemntes using HeapSort.
        sort(a, 10);  
        
        //Printing the elements.
        for (int i=0; i<n; i++)  
        System.out.print(a[i]+" ");
    }  
}  

//Time Complexity : O(nLogn) => If heap is assumed as a binary tree,the height of the tree is (Log n).
//The heapify function works for at most (Log n) times.
//Heapify is called for all the elements of the array.Thus complexity is (nLogn).
//Space Complexity : O(n) => No extra space used.