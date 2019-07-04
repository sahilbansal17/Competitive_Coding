//Bucket Sort in java

import java.util.*;


public class BucketSort {


        //Driver method
	public static void main(String[] args) {
		
               Scanner sc=new Scanner(System.in);

               //Enter the size of array.
               int n=sc.nextInt();

               double a[]=new double[n];

               //Entering array elements.
               for(int i=0;i<n;i++)
                  a[i]=sc.nextDouble();

	       double res[] = new double[a.length];
		
               //Calling a function named buket.
	       res = bucket(a,a.length);
                  

	       //Printing the sorted array. 
               for(int i=0;i<res.length;i++)
	         System.out.println(res[i]);
	}

	//Method implementing bucket sort.
	public static double[] bucket(double arr[], int n)
	{
	    //  Create n empty buckets
	    ArrayList<ArrayList<Double>> b=new ArrayList<ArrayList<Double>>();
	    
	    for(int i=0;i<n;i++)
	    	b.add(new ArrayList<Double>());
	    	    
	    
	    //  Put array elements in different buckets
	    for (int i=0; i<n; i++)
	    {
	       // val is storing the index for an element in bucket
               int val = (int) (n*arr[i]);

	       b.get(val).add(arr[i]);
	    }
	 
	    //  Sort all buckets individualy.
	    for (int i=0; i<n; i++)
	       Collections.sort(b.get(i));
	 
	    //  Concatenate all buckets into arr[]
	    int num = 0;
	    for (int i = 0; i < n; i++)
	        for (int j = 0; j < b.get(i).size(); j++)
	          arr[num++] = b.get(i).get(j);
	
	   return arr;
	
	
	}

}




//Time Complexity - The average case complexity is O(n) 
//but in worst case the complexity is O(n^2) since in this case all the elements are stored in only one bucket.
