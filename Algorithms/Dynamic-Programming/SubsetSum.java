
//Given an array of integers and a target sum, we have to determine if there exists 
//any subset of the given array whose elements sum to the target sum. If we can not 
//find such an array, we have to print the minimum difference of the target sum with 
//the sum we could find a subset for in the given array.

//		Author - Aastha Aneja (Github handle - Aashu24)
//		Email - anejaaastha@gmail.com
	
import java.util.Scanner;

public class SubsetSum {

	public static void main(String args[]) {

		Scanner in = new Scanner(System.in);

		System.out.println("Enter number of elements in array:");

		// input for number of elements
		int n = in.nextInt();

		// array declaration
		int[] array = new int[n];

		System.out.println("Enter array elements:");

		// loop to take array input
		for (int i = 0; i < n; i++) {
			array[i] = in.nextInt();
		}

		System.out.println("Enter the target sum:");

		// input for target sum
		int targetSum = in.nextInt();

		// function call to find Subsets
		int ans = findSubsets(array, targetSum);

		// if a subset is found
		if (ans == 1) {
			System.out.println("Yes! There exists a subset of the given array with the taget sum");
		}
		// if no subset is found with the given sum
		else {
			System.out.println("There doesn't exist any subset of the given array with the target sum.");
			System.out.println("Minimum difference of target sum from found sum = " + ans);
		}
	}

	public static int findSubsets(int[] array, int targetSum) {
		// subsetSums[i][j] stores true if there exists a subset in the given array with
		// the sum i from the elements 0 to j-1 of the given array
		boolean subsetSums[][] = new boolean[targetSum + 1][array.length + 1];

		// If the targetSum is 0 then we don't need to include any element in the
		// subset, so we can mark subsetSums[0][i] to be true
		for (int i = 0; i <= array.length; i++)
			subsetSums[0][i] = true;

		// Similarly, if the subset contains 0 elements and the targetSum is non-zero,
		// we can't create a subset with the given sum
		for (int i = 1; i <= targetSum; i++)
			subsetSums[i][0] = false;

		// these loops fill up the subsetSums DP 2D array
		for (int i = 1; i <= targetSum; i++) {
			for (int j = 1; j <= array.length; j++) {

				// If we don't include the j th element in the subset
				subsetSums[i][j] = subsetSums[i][j - 1];

				// To include the j th element, we need to check if it is smaller than the
				// targetSum i.e. i here
				if (i >= array[j - 1])

					// If this element can be included then we OR its value with
					// subsetSums[i-array[j-1][j-1] to check if a subset with the targetSum
					// i-array[j-1] (i- current element) can be formed using all the elements that
					// came before it
					subsetSums[i][j] = subsetSums[i][j] || subsetSums[i - array[j - 1]][j - 1];
			}
		}

		// subsetSums[targetSum][array.length] will contain true if we were able to find
		// a subset with the targetSum using some elements of the given array
		if (subsetSums[targetSum][array.length]) {
			return 1;
		}

		// If we were unable to find a subset with the given targetSum, we iterate over
		// the DP array to find the closest sum to targetSum that can be formed using
		// the array's elements
		for (int i = targetSum; i >= 0; i--) {
			for (int j = array.length; j >= 0; j--) {

				// If such an element is found, we return i i.e. the sum at that point
				if (subsetSums[i][j]) {
					return i;
				}
			}
		}

		// This is just to satisfy the Java compiler as the method must return an
		// integer value
		return -1;
	}

}

// Time complexity analysis -

// This method will take O(mn) space where m is the targetSum and n is the
// number of elements in the given array to fill up the DP table subsetSums.

// Space complexity analysis -

// this method will take O(mn) extra space where m is the targetSum and n is the
// number of elements in the given array to create the DP table subsetSums