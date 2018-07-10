//Given an array of integers, the problem is to sort the array in wave form 
//i.e. in a way that elements of array are in the order arr[0] >= arr[1] <= 
//arr[2] >= arr[3] <= arr[4] >= ....

//		Author - Aastha Aneja (Github handle - Aashu24)
//		Email - anejaaastha@gmail.com

import java.util.*;

public class WaveSort {

	public static void main(String args[]) {

		// scanner
		Scanner in = new Scanner(System.in);

		System.out.println("Enter size of array:");

		// input for array size
		int n = in.nextInt();

		// array declaration
		int[] array = new int[n];

		// array input
		for (int i = 0; i < n; i++) {
			array[i] = in.nextInt();
		}

		// wave sort function call
		waveSort(array);

		// printing final array output after wave sort
		for (int i = 0; i < n; i++) {
			System.out.print(array[i] + " ");
		}
	}

	// This function sorts the array in wave form by traversing the array once and
	// simply swapping elements to make it in a wave form. The idea is that if we
	// check all elements at even indices and swap them according to our question,
	// we won't need to check the elements at odd positions. If the current element
	// is less than its previous element at odd position, we swap the two and if it
	// is larger, we swap it with its next element.
	public static void waveSort(int[] array) {

		// Traversing the array considering only even positions
		for (int i = 0; i < array.length; i = i + 2) {

			// if current element is less than its previous element, we swap them
			if (i > 1 && array[i] < array[i - 1]) {
				swap(array, i, i - 1);
			} else if (i + 1 < array.length) {

				// if current element is greater than its previous element, we swap it with the
				// next element
				swap(array, i, i + 1);
			}
		}
	}

	// this function swaps the elements at indices a and b in the array
	public static void swap(int[] array, int a, int b) {
		int temp = array[a];
		array[a] = array[b];
		array[b] = temp;
	}
}

// Time complexity analysis -

// This solution takes O(n) time as we traverse the array only once and make
// swaps accordingly.

//Space complexity analysis - 

//This solution takes O(1) extra space.