
//Given Q queries, with each query consisting of two integers L and R, the task is to find the total numbers between L and R (Both inclusive), having atmost three set bits in their binary representation.
//The values of L and R lie within the range [0, 10^18] (both inclusive).
//Example:
//Input : Q = 2
//L = 3, R = 7
//L = 10, R = 16
//Output : 5
//6
//For the first query, valid numbers are 3, 4, 5, 6, and 7.
//For the second query, valid numbers are 10, 11, 12, 13, 14 and 16.

//Author - Aastha Aneja (Github handle - Aashu24)
//Email - anejaaastha@gmail.com

import java.util.*;
import java.io.*;

public class RangeQuery {

	public static void main(String[] args) {

		// scanner
		Scanner in = new Scanner(System.in);

		System.out.println("Enter number of queries:");

		// input for number of queries
		int q = in.nextInt();

		// this makes an array list of queries objects to store the q queries
		ArrayList<Query> queries = new ArrayList<>();

		while (q > 0) {

			System.out.println("Enter value of L:");

			// to store left limit
			long l = in.nextLong();

			System.out.println("Enter value of R:");

			// to store right limit
			long r = in.nextLong();

			// we create a query object with the entered values for L and R
			Query obj = new Query(l, r);

			// this adds the query obj to the array list of queries
			queries.add(obj);

			q--;
		}

		// function call to answer the given queries
		answerQueries(queries);
	}

	// this class stores the l and r i.e. range of a particular query
	static class Query {
		long L;
		long R;

		// constructor
		public Query(long l, long r) {
			this.L = l;
			this.R = r;
		}
	}

	// It returns index of first element which is greater than searched value (value
	// in function arguments).
	// If searched element is larger than any array element, function
	// returns first index after last element. It just implements Binary search for
	// this.
	public static int upperBound(ArrayList<Long> validNumbers, Long value) {

		// low is initially at first element
		int low = 0;

		// high is initially at last element
		int high = validNumbers.size() - 1;

		// this loop runs until low and high cross each other
		while (low < high) {

			// we find mid of the elements under consideration
			int mid = (low + high) / 2;

			// now we compare the given value to be searched with the value at mid index and
			// update low or high accordingly
			if (value >= validNumbers.get(mid)) {
				low = mid + 1;
			} else {
				high = mid;
			}
		}
		return low;
	}

	public static void answerQueries(ArrayList<Query> queries) {
		// Set of Numbers having at most 3 set bits
		// arranged in non-descending order. We create a set because a set can't contain
		// duplicate elements.
		Set<Long> allNum = new HashSet<>();

		// 0 Set bits - only the number 0 has 0 set bits
		allNum.add(0L);

		// Iterate over all possible combinations of i, j, k for
		// 60 bits. And add all the numbers with 0, 1 or 2 set bits into
		// the set allNum.
		for (int i = 0; i <= 60; i++) {
			for (int j = 0; j <= 60; j++) {
				for (int k = 0; k <= 60; k++) {

					// For one set bit, check if i, j, k are equal
					// if yes, then set that bit and add it to the set. If i,j and k are equal, it
					// means that ith bit of that number is set. We set its ith bit by left shifting
					// 1L (1 in Long) by i bits.
					if (i == j && j == k) {
						allNum.add(1L << i);
					}

					// For two set bits, two of the three variable i,j,k
					// will be equal and the third will not be. Set both
					// the bits where two variables are equal and the bit
					// which is not equal, and add it to the set
					else if (i == j && j != k) {
						long toAdd = (1L << i) + (1L << k);
						allNum.add(toAdd);
					} else if (i == k && k != j) {
						long toAdd = (1L << i) + (1L << j);
						allNum.add(toAdd);
					} else if (j == k && k != i) {
						long toAdd = (1L << j) + (1L << i);
						allNum.add(toAdd);
					}

					// Setting all the 3 bits
					else {
						long toAdd = (1L << i) + (1L << j) + (1L << k);
						allNum.add(toAdd);
					}

				}
			}
		}

		// Now we add all the numbers to an array list so that it can be sorted
		ArrayList<Long> validNumbers = new ArrayList<>();
		for (Long num : allNum) {
			validNumbers.add(num);
		}

		// this sorts the array list of valid numbers
		Collections.sort(validNumbers);

		// Answer queries by applying binary search
		for (int i = 0; i < queries.size(); i++) {
			long L = queries.get(i).L;
			long R = queries.get(i).R;

			// Swap L and R if R is smaller than L
			if (R < L) {
				long temp = L;
				L = R;
				R = temp;
			}

			if (L == 0) {
				int indxOfLastNum = upperBound(validNumbers, R);
				System.out.println("Answer: "+indxOfLastNum + 1);
			} else {
				int indxOfFirstNum = upperBound(validNumbers, L);
				int indxOfLastNum = upperBound(validNumbers, R);
				System.out.println("Answer: "+(indxOfLastNum - indxOfFirstNum + 1));
			}

		}

	}

}

// Time complexity analysis -

// Its time complexity is O((Maximum Number of Bits)^3 + Q * logN), where Q is
// the number of queries and N is the size of set containing all valid numbers.

// Space complexity analysis -

// Its space complexity is O(k) where k is the number of valid numbers according
// to the question as we store these numbers first in a set and then in an array
// list to sort them.
