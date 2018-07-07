//Given one string, we have to find the minimum number of operations (edits) that can 
//be performed on the string to make it a palindrome. The following operations can be 
//performed on the string:

//1. Inserting a character (cost=1)
//2. Removing a character (cost=2)
//3. Replacing a character with some other character (cost=3)

//		Author - Aastha Aneja (Github handle - Aashu24)
//		Email - anejaaastha@gmail.com

//Explanation - If you look at it closely, one replace operation is equivalent to one 
//insertion and one removal. So, we don't need to consider the replace character 
//operation separately.

import java.util.Scanner;

public class EditDistance {

	// a variable to compare and find minimum number of operations
	static int max = Integer.MAX_VALUE;
	static StringBuilder palin = new StringBuilder();

	public static void main(String[] args) {

		// scanner declaration
		Scanner in = new Scanner(System.in);

		System.out.println("Enter the string that you want to convert into a palindrome:");

		// str stores the string whose palindrome we wish to find
		String str = in.next();

		StringBuilder palindrome = new StringBuilder(str);
		// function call
		makePalindrome(str, 0, str.length() - 1, 0, palindrome);

		System.out.println("Minimum number of operations required:");

		// After the function makePalindrome has completed its execution, the variable
		// max contains the answer
		System.out.println(max);
		
		//printing the palindrome formed
		System.out.println(palin);
	}

	public static void makePalindrome(String str, int first, int last, int cost, StringBuilder palindrome) {

		// if first>=last is true, this means that we have traversed the whole string
		// and now we can compare its cost to max
		if (first >= last) {
			if (cost < max) {
				max = cost;
				palin = palindrome;
			}
			return;
		}

		// If the characters are same, then we don't need to perform any operation on
		// them and we check the next characters
		if (str.charAt(first) == str.charAt(last)) {
			makePalindrome(str, first + 1, last - 1, cost, palindrome);
		}
		// if the characters are not same, we consider three possibilities
		else {
			// One possibility is to insert two characters, one at the first pointer and one
			// at the last pointer which increases the cost by 2
			StringBuilder p1 = new StringBuilder();

			// These functions add the character at first just after the character at last
			// and the character at last just after the character at first
			p1.append(palindrome.substring(0, first + 1));
			p1.append(palindrome.charAt(last));
			p1.append(palindrome.substring(first + 1, last + 1));
			p1.append(palindrome.charAt(first));
			p1.append(palindrome.substring(last + 1));

			// function call for first possibility
			makePalindrome(str, first + 1, last - 1, cost + 2, p1);

			// Another possibility is to insert the character at first at the position
			// currently last is at which increases the cost by 1
			StringBuilder p2 = new StringBuilder();

			// These functions add the character at first at the position last is at
			p2.append(palindrome.substring(0, last + 1));
			p2.append(palindrome.charAt(first));
			p2.append(palindrome.substring(last + 1));

			// function call for second possibility
			makePalindrome(str, first + 1, last, cost + 1, p2);

			// The third possibility is to insert the character at last at the position
			// currently first is at which increases the cost by 1
			StringBuilder p3 = new StringBuilder();

			// These functions add the character at last at the first's position
			p3.append(palindrome.substring(0, first + 1));
			p3.append(palindrome.charAt(last));
			p3.append(palindrome.substring(first + 1));

			// function call for third possibility
			makePalindrome(str, first, last - 1, cost + 1, p3);
		}
	}

}

// Time complexity analysis -

// As there are three recursive calls at every step of the recursion, the time
// complexity should be O(3^n) where n is the length of the string.