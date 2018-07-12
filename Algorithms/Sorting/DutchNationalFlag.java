
//Given an array that contains only 0s, 1s and 2s, we have to sort the array 
//in linear time using the Dutch National Flag Algorithm. The Dutch National 
//Flag Algorithm takes three variables low (initially 0), mid(initially 0) 
//and high (initially points at last element of array). It traverses the whole 
//array using mid and segregates 0s,1s and 2s. If the value at mid is 0, we 
//swap the elements array[low] and array[mid]. This is because all 0s should 
//occur at the beginning in the sorted array. After this, we increment both 
//low and mid. If value at mid is 1, we just increment the value of mid 
//because we want to keep all 1s in the middle. After we have encountered 
//the first 1, if we encounter another 0, then low will be pointing at the 
//first 1 we encountered and we will swap array[low] and array[mid]. If the
//value at mid is 2, we swap the values of array[mid] and array[high] and
//then decrement value of high. This is because we want all 2s to be at the 
//end. This sorts the array in linear time.

import java.util.Scanner;

public class DutchNationalFlag {

	public static void main(String[] args) {
		// scanner
		Scanner in = new Scanner(System.in);

		System.out.println("Enter size of array:");

		// input for array size
		int n = in.nextInt();

		// array declaration
		int[] array = new int[n];

		System.out.println("Enter array elements:");

		// input for array elements
		for (int i = 0; i < n; i++) {
			array[i] = in.nextInt();
		}

		// function call to sort the array
		sortArray(array);

		// print the final sorted array
		for (int i = 0; i < n; i++) {
			System.out.println(array[i]);
		}

	}

	// This function applies the Dutch National Flag algorithm and sorts the array.
	public static void sortArray(int[] array) {

		// initially low=0
		int low = 0;

		// initially high points at last element
		int high = array.length - 1;

		// initially mid=0 as we start traversal from first array element
		int mid = 0;

		// we traverse the array until mid and high cross each other
		while (mid <= high) {

			// we check the value at mid index
			switch (array[mid]) {

			// if it is 0, we swap values at low and mid
			case 0:
				swap(array, low, mid);
				low++;
				mid++;
				break;

			// if it is 1, we increment mid to ignore that element
			case 1:
				mid++;
				break;

			// if it is 2, we swap values at mid and high
			case 2:
				swap(array, mid, high);
				high--;
				break;
			}
		}
	}

	// This function swaps the array elements at indices i and j
	public static void swap(int[] array, int i, int j) {
		array[i] = array[i] + array[j];
		array[j] = array[i] - array[j];
		array[i] = array[i] - array[j];
	}

}

// Time complexity analysis -

// As this algorithm traverses the array only once, so its time complexity is
// O(n) where n is the size of the input array.

// Space complexity analysis -

// This algorithm uses O(n) space as input space for the input array where n is
// the size of the array and O(1) auxiliary space. So, the total space
// complexity is O(n).