//Given a gold mine of n*m dimensions. Each field in this mine 
//contains a positive integer which is the amount of gold in tons. 
//Initially, the miner is in the first column but can be at any 
//row. He can move only (right->, right up /, right down) that is 
//from a given cell, the miner can move to the cell diagonally up
//towards the right or right or diagonally down towards the right.
//Find out the maximum amount of gold he can collect. This is a 
//DP problem.

//		Author - Aastha Aneja (Github handle - Aashu24)
//		Email - anejaaastha@gmail.com

import java.util.Scanner;

public class Goldmine {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);

		System.out.println("Enter no. of rows:");

		// rows
		int n = in.nextInt();

		System.out.println("Enter no. of columns:");

		// columns
		int m = in.nextInt();

		// mine of size n*m
		int[][] mine = new int[n][m];

		System.out.println("Enter values of mine:");

		// mine input
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				mine[i][j] = in.nextInt();
			}
		}

		// required function call
		goldmine(mine);

	}

	// this function calculates the maximum value the miner can dig and also the
	// path he has to follow for that
	public static void goldmine(int[][] mine) {

		// to store max values
		int[][] smine = new int[mine.length][mine[0].length];

		// to store path
		String[][] path = new String[mine.length][mine[0].length];

		// overall max
		int omax = Integer.MIN_VALUE;

		// to store row where miner should start digging
		int maxRow = -1;

		// to store column where miner should start digging
		int maxCol = -1;

		// we iterate over the mine
		// column loop
		for (int c = mine[0].length - 1; c >= 0; --c) {

			// row loop
			for (int r = 0; r < mine.length; ++r) {
				// row + 1
				int rp1 = r + 1;

				// row - 1
				int rm1 = r - 1;

				// column + 1
				int cp1 = c + 1;

				// last column
				if (c == mine[0].length - 1) {

					// if we are in last column, miner can get maximum value at that point only
					smine[r][c] = mine[r][c];
					path[r][c] = r + "-" + c;
				}
				// first row
				else if (r == 0) {

					// miner can move either right or right/down

					// if moving right is more beneficial
					if (smine[r][cp1] > smine[rp1][cp1]) {

						// we move right
						smine[r][c] = mine[r][c] + smine[r][cp1];
						path[r][c] = r + "-" + c + " " + path[r][cp1];
					}
					// if moving right down is more beneficial
					else {

						// we move right down
						smine[r][c] = mine[r][c] + smine[rp1][cp1];
						path[r][c] = r + "-" + c + " " + path[rp1][cp1];
					}

				}
				// last row
				else if (r == mine.length - 1) {

					// miner can move either right or right up

					// if moving right is more beneficial
					if (smine[r][cp1] > smine[rm1][cp1]) {
						// miner moves right
						smine[r][c] = mine[r][c] + smine[r][cp1];
						path[r][c] = r + "-" + c + " " + path[r][cp1];
					}
					// if moving right up is more beneficial
					else {
						// miner moves right up
						smine[r][c] = mine[r][c] + smine[rm1][cp1];
						path[r][c] = r + "-" + c + " " + path[rm1][cp1];
					}
				}
				// if we are somewhere in the middle, miner can move right, right down or right
				// up
				else {
					// if moving right is more beneficial
					if (smine[r][cp1] > smine[rp1][cp1] && smine[r][cp1] > smine[rm1][cp1]) {

						// miner moves right
						smine[r][c] = mine[r][c] + smine[r][cp1];
						path[r][c] = r + "-" + c + " " + path[r][cp1];
					}
					// if moving right down is more beneficial
					else if (smine[rm1][cp1] > smine[rp1][cp1] && smine[rm1][cp1] > smine[r][cp1]) {

						// miner moves right down
						smine[r][c] = mine[r][c] + smine[rm1][cp1];
						path[r][c] = r + "-" + c + " " + path[rm1][cp1];
					}
					// if moving right up is more beneficial
					else {

						// miner moves right up
						smine[r][c] = mine[r][c] + smine[rp1][cp1];
						path[r][c] = r + "-" + c + " " + path[rp1][cp1];
					}
				}

				// we compare this value with overall max and update it if required
				if (smine[r][c] > omax) {
					omax = smine[r][c];
					maxRow = r;
					maxCol = c;
				}
			}

		}

		// finally, we print the ans
		System.out.println("Max value miner can dig : " + omax);
		System.out.println("Path : " + path[maxRow][maxCol]);

	}

}

// Time complexity analysis -

// The time complexity of the function will be O(n*m) where n is no. of rows and
// m is no. of columns in the mine as we have to fill
// the whole 2d matrix for smine to find maximum value for each possible value
// in mine.

// Space complexity analysis -

// The extra space used by this algorithm is O(n*m) where n is no. of rows and
// m is no. of columns in the mine as we made two 2d
// matrices smine and path to store maximum value and path for it.