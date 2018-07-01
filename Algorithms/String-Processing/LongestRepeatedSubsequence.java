// The problem is to find the longest repeated subsequence for a given input string. 
//A longest repeated subsequence is the longest subsequence of a string that occurs 
//in the string two or more than two times such that the two subsequence don’t have 
//same string character at same position, i.e., any i’th character in the two 
//subsequences shouldn’t have the same index in the original string.

//		Author - Aastha Aneja (Github handle - Aashu24)
//		Email - anejaaastha@gmail.com

import java.util.Scanner;

public class LongestRepeatedSubsequence {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);

		System.out.println("Enter the string whose longest repeated subsequence you wish to find:");

		// Input string
		String str = in.next();

		System.out.print("Longest Repeated Subsequence : ");

		System.out.println(fetchLRS(str));

		in.close();
	}

	// The function fetchLRS takes the given string as input and returns the longest
	// repeated subsequence of that string. It follows a dynamic programming
	// approach. This problem is very similar to the Longest common subsequence
	// problem. This function computes the length of the longest repeated
	// subsequence in a similar fashion as in LCS by using a 2d matrix namely
	// lengths of size (str.length+1)*(str.length+1) by taking an additional
	// condition that the indexes of the character should not be same which is a
	// requirement of the longest repeated subsequence problem. In a way, it
	// calculates the LCS of the given string with the same string by applying an
	// additional check on the indexes.
	public static String fetchLRS(String str) {

		// 2d matrix to store lengths of LRS starting from 0 to str.length (inclusive).
		// This matrix will store lengths of LRS of str with str from lengths 0 to
		// str.length (inclusive).
		int[][] lengths = new int[str.length() + 1][str.length() + 1];

		// These nested loops compare every character of the string with its every
		// character to find out the length of the LRS.
		for (int i = 1; i <= str.length(); i++) {
			for (int j = 1; j <= str.length(); j++) {

				// Additional check to ensure that although the characters are equal but their
				// indexes in the string are different.
				if (str.charAt(i - 1) == str.charAt(j - 1) && i != j) {
					lengths[i][j] = 1 + lengths[i - 1][j - 1];
				} else {
					lengths[i][j] = Math.max(lengths[i][j - 1], lengths[i - 1][j]);
				}
			}
		}

		// StringBuilder to store the LRS
		StringBuilder result = new StringBuilder();

		int i = str.length(), j = i;

		// Loop to fetch the LRS using the lengths matrix and store it in the
		// StringBuilder result in a similar fashion as in LCS
		while (i > 0 && j > 0) {

			// This condition will be true only if the characters were equal but their
			// indexes were different
			if (lengths[i][j] == lengths[i - 1][j - 1] + 1) {
				// Appending the character to the result
				result.append(str.charAt(i - 1));
				i--;
				j--;
			} else if (lengths[i][j] == lengths[i - 1][j])
				i--;
			else
				j--;
		}

		// As we get the LRS in a reverse pattern, we have to reverse the result string
		// to get the original LRS.
		result.reverse();

		// Statement to return the result StringBuilder as a string
		return result.toString();
	}
}

// Time complexity analysis :

// As we have to fill up a 2d matrix lengths of size (n+1)*(n+1) to get the
// length of the longest repeated subsequence where n is the length of the input
// string, the time complexity of this solution will be O((n+1)*(n+1)) which is
// equivalent to O(n^2).

// Space complexity analysis :

// As this solution uses a dynamic programming approach and hence creates a 2d
// matrix to store the lengths of the LRS, it takes extra space to store this
// matrix of size (n+1)*(n+1). Therefore, the space complexity of this solution
// will be O(n^2).