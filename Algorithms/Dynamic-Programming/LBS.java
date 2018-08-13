//Given an array arr[0 … n-1] containing n positive integers, a subsequence 
//of arr[] is called Bitonic if it is first increasing, then decreasing. 
//Write a function that takes an array as argument and returns the length 
//of the longest bitonic subsequence. This is a DP problem.

//		Author - Aastha Aneja (Github handle - Aashu24)
//		Email - anejaaastha@gmail.com


import java.util.Scanner;

public class LBS {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		// scanner
		Scanner in = new Scanner(System.in);

		System.out.println("Enter size of array:");

		// size of array
		int n = in.nextInt();

		// array declaration
		int[] arr = new int[n];

		System.out.println("Enter array elements:");

		// array input
		for (int i = 0; i < n; ++i) {
			arr[i] = in.nextInt();
		}

		// required function call
		findLBS(arr);
	}

	// this function finds the length of the Longest bitonic subsequence for a given
	// array by finding its longest increasing subsequence and longest decreasing
	// subsequence and merging them
	public static void findLBS(int[] arr) {

		// This array will store the length of the longest increasing subsequence that
		// ends at a particular index i, this will be computed from left to right
		int[] lisLength = new int[arr.length];

		// For first element of array, the length of LIS will be 1 since the LIS ending
		// at that element contains only that element itself
		lisLength[0] = 1;

		// now we iterate over the array and fill the array lisLength with lengths of
		// LIS ending at element arr[i] for index i
		for (int i = 1; i < arr.length; ++i) {

			// we check for all elements before arr[i]
			for (int j = 0; j <= i - 1; ++j) {

				// and if we find an element that is smaller than arr[i]
				if (arr[j] < arr[i]) {

					// and the length of it's LIS is greater than that for arr[i]
					if (lisLength[j] > lisLength[i]) {

						// we update the length as now we can make a new LIS that will contain the LIS
						// at index j and the element at index i in the end
						lisLength[i] = lisLength[j];
					}
				}
			}

			// this is to consider the element at index i in the LIS
			lisLength[i] += 1;
		}

		// similarly, we find the longest decreasing subsequence for the array computing
		// it from right to left and ldsLength array stores the length of LDS that
		// starts at an element arr[i] for index i
		int[] ldsLength = new int[arr.length];

		// The LDS for the last element will be of length 1 since it will only contain
		// that element
		ldsLength[arr.length - 1] = 1;

		// now we iterate over the array and fill the array ldsLength
		for (int i = arr.length - 2; i >= 0; --i) {

			// we check all elements that come after arr[i]
			for (int j = arr.length - 1; j >= i + 1; --j) {

				// and if we find an element arr[j] that is smaller than arr[i]
				if (arr[j] < arr[i]) {

					// and whose ldsLength is greater than that for arr[i]
					if (ldsLength[j] > ldsLength[i]) {

						// we update ldsLength[i] as now we can make a LDS that has its first element as
						// arr[i] and the LDS of arr[j]
						ldsLength[i] = ldsLength[j];
					}
				}
			}

			// this is to consider arr[i] in the LDS
			ldsLength[i] += 1;
		}

		// now to find the overall maximum length of LBS, we take a variable omax
		// initially 0
		int omax = 0;

		// now we iterate over lisLength and ldsLength
		for (int i = 0; i < arr.length; ++i) {

			// and if we find an element at which lisLength+ldsLength is greater than omax
			if (lisLength[i] + ldsLength[i] > omax) {

				// we update omax with lisLength + ldsLength - 1 (the -1 is there because the
				// element arr[i] is considered twice here, once in lis and once in lds)
				omax = lisLength[i] + ldsLength[i] - 1;
			}
		}

		// now we print the final max length
		System.out.println(omax);

	}
}

// Time complexity analysis -

// The function findLBS takes O(n^2) where n is the number of elements in the
// array time because there are two nested for loops
// in it to calculate the LIS and the LDS.

// Space complexity analysis -

// The function findLBS takes O(n) extra space because we take two arrays namely
// lisLength and ldsLength to store the lengths of LIS and LDS for every element
// in the array.