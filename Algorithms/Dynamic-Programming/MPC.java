
//Given a string, a partitioning of the string is a palindrome partitioning 
//if every substring of the partition is a palindrome. For example, 
//“aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. 
//Determine the fewest cuts needed for palindrome partitioning of a given
//string. This is a DP problem.

//		Author - Aastha Aneja (Github handle - Aashu24)
//		Email - anejaaastha@gmail.com

import java.util.Scanner;

public class MPC {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);

		System.out.println("Enter a string:");

		// input string
		String str = in.next();

		// required function call
		System.out.println(findMpc(str));

	}

	// This function returns the minimum number of partitions required to divide a
	// string in such a way that all its parts become planidromes
	public static int findMpc(String str) {

		// This array will store true if the substring starting from i to j is a
		// palindrome in palinres[i][j]
		boolean[][] palinres = new boolean[str.length()][str.length()];

		// we fill this 2d matrix diagonally by using gap variable, gap represents gap
		// between i and j
		for (int gap = 0; gap < str.length(); ++gap) {

			// initially i will be 0 and j will be i+gap
			int i = 0, j = i + gap;

			// we will iterate till j doesn't go out of bounds
			while (j < str.length()) {

				// if gap is 0, it means that the length of the substring is 1 and a string of
				// length 1 is always a palindrome
				if (gap == 0) {

					// so we put true
					palinres[i][j] = true;
				}
				// if gap is 1, it means length of substring is 2 and a string of length 2 is a
				// plaindrome if both its characters are same
				else if (gap == 1) {

					// this will put true if characters are same and false if characters are
					// different
					palinres[i][j] = str.charAt(i) == str.charAt(j);
				}
				// if length is more than 2, we check if the first and last characters are same
				// and if the rest of the string in the middle is a palindromes
				else {
					palinres[i][j] = str.charAt(i) == str.charAt(j) && palinres[i + 1][j - 1];
				}

				// increment i
				i++;

				// increment j
				j++;
			}
		}

		// This matrix will store the minimum number of partitions required to make all
		// parts palindromes for a string from i to j
		int[][] mpc = new int[str.length()][str.length()];

		// we iterate over this matrix similarly using gap variable diagonally
		for (int gap = 0; gap < str.length(); ++gap) {

			// initially i=0 and j=gap+i
			int i = 0, j = i + gap;

			// we will iterate till j doesn't go out of bounds
			while (j < str.length()) {

				// if gap is 0, it means that the length of the substring is 1 and a string of
				// length 1 is always a palindrome
				if (gap == 0) {
					// so min no. of cuts is 0
					mpc[i][j] = 0;
				}
				// if gap is 1, it means length of substring is 2 and a string of length 2 is a
				// plaindrome if both its characters are same
				else if (gap == 1) {
					// and the string is a palindrome
					if (palinres[i][j])
						// min no. of cuts required will be 0
						mpc[i][j] = 0;
					else
						// min no. of cuts required is 1
						mpc[i][j] = 1;
				}
				// if length is more than 2
				else {

					// and if the string is a palindrome
					if (palinres[i][j]) {
						// min no. of cuts required is 0
						mpc[i][j] = 0;
						// increment i and j
						i++;
						j++;
						// and continue to next iteration
						continue;
					}

					// if the string is not a palindrome, we need to find minimum no. of cuts for it
					int minValue = Integer.MAX_VALUE;

					// we try and divide the string into halves by putting a cut at every possible
					// position and choose the one that gives us min no. of cuts
					for (int cut = i; cut < j; ++cut) {

						// first part of string after cut
						int fp = mpc[i][cut];

						// second part of string after cut
						int sp = mpc[cut + 1][j];

						// factor is the minimum no. of cuts for whole string which will be cuts for fp
						// + cuts for sp + 1(to divide string into fp and sp)
						int factor = fp + sp + 1;

						// if this factor is less than overall min cuts
						if (factor < minValue) {
							// we update minValue
							minValue = factor;
						}
					}

					// finally we put the minValue in mpc[i][j]
					mpc[i][j] = minValue;

				}

				// increment i and j
				i++;
				j++;
			}
		}

		// the ans will be stored in mpc[0][str.length()-1]
		return mpc[0][str.length() - 1];
	}

}

// Time complexity analysis -

// The time complexity of the function will be O(n^2) as we have to fill the
// whole 2d matrix for palinres and mpc.

// Space complexity analysis -

// The extra space used by this algorithm is O(n^2) as we made two 2d matrices
// palinres and mpc.