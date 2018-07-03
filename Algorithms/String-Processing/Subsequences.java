
//Given a string, we have to find out all subsequences of it. A String is a 
//subsequence of a given String, that is generated by deleting some character 
//of a given string without changing its order.

//		Author - Aastha Aneja (Github handle - Aashu24)
//		Email - anejaaastha@gmail.com
	


import java.util.ArrayList;
import java.util.Scanner;

public class Subsequences {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);

		System.out.println("Enter string whose subsequences you wish to find :");

		// Input string
		String str = in.next();

		System.out.println("Subsequences :");

		// Result of subsequences
		ArrayList<String> result = getSubSequence(str);
		System.out.println(result);
	}

	// This is a recursive function that returns all the possible substrings of a
	// string in the form of an ArrayList of strings. It takes the character of the
	// string at position 0 and concatenates it with the subsequences of the rest of
	// the
	// string. The base case checks if the length of the string has become zero and
	// if it is so then it returns an ArrayList with one empty string in it.
	public static ArrayList<String> getSubSequence(String str) {

		// Base case
		if (str.length() == 0) {
			ArrayList<String> baseResult = new ArrayList<>();
			baseResult.add("");
			return baseResult;
		}

		// cc stands for current character which will always be the character at
		// position 0 of the string.s
		char cc = str.charAt(0);

		// ros stands for rest of the string which is the substring from position 1 of
		// the given string.s
		String ros = str.substring(1);

		// This ArrayList will store the subsequences of the string passed to this
		// function.
		ArrayList<String> myResult = new ArrayList<>();

		// recResult stands for recursive result and it stores all the subsequences of
		// the string ros which are returned recursively by this function.
		ArrayList<String> recResult = getSubSequence(ros);

		// This loop fills up the ArrayList myResult by concatenating the current
		// character with each string found in the recResult to make all possible
		// substrings of the string passed to this function.
		for (int i = 0; i < recResult.size(); i++) {
			myResult.add(recResult.get(i));
			myResult.add(cc + recResult.get(i));
		}

		return myResult;
	}

}

// Time complexity analysis :

// When the function hits the base case, one string is added in the ArrayList,
// so size of ArrayList becomes 1. So, when one character is present in the
// string, the for loop to concatenate that character with the subsequences of
// the rest of the string will run once. Now, the size of the ArrayList becomes
// two because in one iteration of the for loop, two elements are added to the
// ArrayList. When the string contains two characters, the for loop will run
// twice (since size of ArrayList returned is two). Now, the ArrayList will
// contain four elements and so next time, the loop will run four times. So, the
// complexities of successive recursive calls will be as follows :
// 1 + 2 + 4 + 8 + ...... + (2^n - 1) = 2^n
// As a string of n characters has (2^n - 1) subsequences. Therefore, the time
// complexity of this recursive function will be O(2^n).

// Space complexity analysis :

// There will be n recursive calls for a string of length n and every recursive
// call will make an ArrayList of maximum size (2^n - 1). So, the space
// complexity of this function will be O(2^n) and some extra memory for the
// recursion stack.