
import java.util.*;

// bubble sort
 class BubbleSort {

	static void bubble(int[] a) {
		
                //After the first iteration of the outer loop,the largest element will be stored at the last index and so on.
		for (int i = 0; i < a.length - 1; i++) {

			for (int j = 0; j < a.length - 1; j++) {
                              
                                //Comparing two adjacent elements and swaping accordingly.
				if(a[j] > a[j + 1]) {
					int temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}	
		}
	}

        //Driver method
	public static void main(String[] args) {

		Scanner sc=new Scanner(System.in);
    
                //Enter size of array.
                int n=sc.nextInt();

                int a[]=new int[n];

                //Taking input elements from user.
                for(int i=0;i<n;i++)
                a[i]=sc.nextInt();

		bubble(a);

		System.out.println("Sorted array: ");
		System.out.println(Arrays.toString(a));
	}
}
//Time Complexity : O(n^2) since two for loops iterating till the length of array are used. 
//Space Complexity : O(1) => No extra space is used.
