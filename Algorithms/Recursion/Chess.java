//Given an input N, a number. N represents the size of a chess board. We’ve a piece standing 
//in top-left corner and it must reach the bottom-right corner. The piece moves as follows –
//a. In any cell, the piece moves like a knight. But out of the possible 8 moves for a knight 
//only the positive ones are valid i.e. both row and column must increase in a move.
//b. On the walls (4 possible walls), the piece can move like a rook as well (in addition of 
//knight moves). But, only the positive moves are allowed i.e. as a rook, piece can move any 
//number of steps horizontally or vertically but in a manner, such that row or column must increase.
//c. On the diagonals (2 possible diagonals), the piece can move like a bishop as well (in addition 
//to the knight and possibly rook moves). But, only the positive moves are allowed i.e. as a bishop, 
//piece can move in a way such that row and column must increase.

//1. Write a recursive function which returns the count of different distinct ways this board can be 
//crossed. Print the value returned.
//
// 2. Write a recursive function which returns an ArrayList of all valid paths. Print the value returned. 
//E.g. Following are two valid paths for a board of size 4
//{0-0}, {2-1}, {3-3}
//{0-0}, {1-2}, {3-3}
//
//3. Write a recursive function which prints all valid paths.

import java.util.ArrayList;
import java.util.Scanner;

public class Chess {

	public static void main(String[] args) {
		// scanner
		Scanner scn = new Scanner(System.in);

		System.out.println("Enter size of board:");

		// input for board size
		int N = scn.nextInt();

		System.out.println("Count of possible ways:");

		// function call 1
		System.out.print(countChessPaths(N, N, 0, 0));

		System.out.println("Output of print path:");

		// function call 2
		printChessPaths(N, N, 0, 0, "");

		System.out.println("Output of get path:");

		// function call 3
		System.out.println(getChessPaths(N, N, 0, 0));
	}

	// function to count the no. of ways the board can be crossed - er=end row,
	// ec=end column, cr=current row, cc=current column
	public static int countChessPaths(int er, int ec, int cr, int cc) {

		// if cr==er and cc==ec, this means that we have reached the end of the board
		// i.e. our destination
		if (cr == er && cc == ec) {
			return 1;
		}

		// if cr has crossed er or cc has crossed ec, this means we need to backtrack
		if (cr > er || cc > ec) {
			return 0;
		}

		// variable to store the number of paths
		int count = 0;

		// knight move 1
		count += countChessPaths(er, ec, cr + 2, cc + 1);

		// knight move 2
		count += countChessPaths(er, ec, cr + 1, cc + 2);

		// rook move
		if (cr == 0 || cr == er || cc == 0 || cc == ec) {

			// horizontal
			for (int col = cc + 1; col <= ec; col++) {
				count += countChessPaths(er, ec, cr, col);
			}

			// vertical
			for (int row = cr + 1; row <= er; row++) {
				count += countChessPaths(er, ec, row, cc);
			}
		}

		// bishop move
		if (cr == cc || cr + cc == ec) {
			for (int col = cc + 1, row = cr + 1; col <= ec && row <= er; col++, row++) {
				count += countChessPaths(er, ec, row, col);
			}
		}

		return count;
	}

	// This function prints all the possible paths to cross the board - osf means
	// output so far
	public static void printChessPaths(int er, int ec, int cr, int cc, String osf) {

		// if cr==er and cc==ec, this means that we have reached the end of the board
		// i.e. our destination
		if (cr == er && cc == ec) {

			// as we have found one path, we print it
			System.out.println(osf + "{" + cr + "-" + cc + "}");
			return;
		}

		// if cr has crossed er or cc has crossed ec, this means we need to backtrack
		if (cr > er || cc > ec) {
			return;
		}

		// knight move 1
		printChessPaths(er, ec, cr + 2, cc + 1, osf + "{" + cr + "-" + cc + "}K");

		// knight move 2
		printChessPaths(er, ec, cr + 1, cc + 2, osf + "{" + cr + "-" + cc + "}K");

		// rook move
		if (cr == 0 || cr == er || cc == 0 || cc == ec) {

			// horizontal
			for (int col = cc + 1; col <= ec; col++) {
				printChessPaths(er, ec, cr, col, osf + "{" + cr + "-" + cc + "}R");
			}

			// vertical
			for (int row = cr + 1; row <= er; row++) {
				printChessPaths(er, ec, row, cc, osf + "{" + cr + "-" + cc + "}R");
			}
		}

		// bishop move
		if (cr == cc || cr + cc == ec) {
			for (int col = cc + 1, row = cr + 1; col <= ec && row <= er; col++, row++) {
				printChessPaths(er, ec, row, col, osf + "{" + cr + "-" + cc + "}B");
			}
		}
	}

	// This function returns an array list of all the possible paths to cross the
	// board
	public static ArrayList<String> getChessPaths(int er, int ec, int cr, int cc) {

		// if cr==er and cc==ec, this means that we have reached the end of the board
		// i.e. our destination
		if (cr == er && cc == ec) {
			ArrayList<String> baseResult = new ArrayList<>();

			// As we have found one path, we add its end point to the base result and return
			// it
			baseResult.add("{" + cr + "-" + cc + "}");

			return baseResult;
		}

		// if cr has crossed er or cc has crossed ec, this means we need to backtrack
		if (cr > er || cc > ec) {
			ArrayList<String> baseResult = new ArrayList<>();
			return baseResult;
		}

		// This array list will store our final result
		ArrayList<String> myResult = new ArrayList<>(), recResult = null;

		// knight move 1
		recResult = getChessPaths(er, ec, cr + 2, cc + 1);

		for (int i = 0; i < recResult.size(); i++) {
			myResult.add("{" + cr + "-" + cc + "}K" + recResult.get(i));
		}

		// knight move 2
		recResult = getChessPaths(er, ec, cr + 1, cc + 2);

		for (int i = 0; i < recResult.size(); i++) {
			myResult.add("{" + cr + "-" + cc + "}K" + recResult.get(i));
		}

		// rook move
		if (cr == 0 || cr == er || cc == 0 || cc == ec) {

			// horizontal
			for (int col = cc + 1; col <= ec; col++) {
				recResult = getChessPaths(er, ec, cr, col);
				for (int i = 0; i < recResult.size(); i++) {
					myResult.add("{" + cr + "-" + cc + "}R" + recResult.get(i));
				}
			}

			// vertical
			for (int row = cr + 1; row <= er; row++) {
				recResult = getChessPaths(er, ec, row, cc);
				for (int i = 0; i < recResult.size(); i++) {
					myResult.add("{" + cr + "-" + cc + "}R" + recResult.get(i));
				}
			}
		}

		// bishop move
		if (cr == cc || cr + cc == ec) {
			for (int col = cc + 1, row = cr + 1; col <= ec && row <= er; col++, row++) {
				recResult = getChessPaths(er, ec, row, col);
				for (int i = 0; i < recResult.size(); i++) {
					myResult.add("{" + cr + "-" + cc + "}B" + recResult.get(i));
				}
			}
		}

		// this returns our ans
		return myResult;
	}
}

// Time complexity analysis -

// The time complexities for all the three functions is same and is very large
// due to the number of recursive calls. In the worst case, there will be two
// recursive calls for the two knight moves, n calls for the horizontal rook
// moves, n calls for the vertical rook moves and n calls for the bishop moves.
// This makes its time complexity as O((3n+2)^n) for a board of size n which is
// equivalent to O(n^n).

// Space complexity analysis -

// The functions for count and print take O(1) extra space and some extra space
// for the recursion stack. The get function that returns an arraylist of
// possible paths take O(n) extra space where n is the maximum number of ways to
// cross the board and extra space for the recursive stack.