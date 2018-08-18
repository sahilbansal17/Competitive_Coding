//Given a binary matrix, find out the maximum size square sub-matrix with all 1s. This is a DP problem.

//		Author - Aastha Aneja (Github handle - Aashu24)
//		Email - anejaaastha@gmail.com

import java.util.Scanner;

public class MaxSquareSubmatrix {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);

		System.out.println("Enter size of matrix:");

		// rows
		int n = in.nextInt();

		// matrix of size n*m
		int[][] matrix = new int[n][n];

		System.out.println("Enter values of matrix:");

		// matrix input
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				matrix[i][j] = in.nextInt();
			}
		}

		// required function call
		maxSquareSubMatrix(matrix);

	}

	public static void maxSquareSubMatrix(int[][] matrix) {

		// storage - it will store maximum size of square submatrix with all 1's that
		// starts at row r and column c in strg[r][c]
		int[][] strg = new int[matrix.length][matrix.length];

		// destination row
		int dr = strg.length - 1;

		// destination column
		int dc = strg[0].length - 1;

		// overall maximum
		int omax = 0;
		int omaxRow = -1;
		int omaxCol = -1;

		// now we iterate over the matrix
		// row loop
		for (int r = dr; r >= 0; --r) {

			// column loop
			for (int c = dc; c >= 0; --c) {

				// row + 1
				int rp1 = r + 1;

				// column + 1
				int cp1 = c + 1;

				// if we are in last row or last column, largest square submatrix that can be
				// formed will be of size 0 if the element at that position is 0 andof size 1 if
				// the element is 1
				if (r == dr || c == dc) {
					// so we put the element in strg
					strg[r][c] = matrix[r][c];
				}
				// for the rest of the matrix
				else {

					// if element is 0
					if (matrix[r][c] == 0) {

						// max size square submatrix of all 1's starting at that index is also of size 0
						strg[r][c] = 0;
					}
					// if element is 1
					else {

						// we find out min of strg[rp1][cp1], strg[rp1][c] and strg[r][cp1] and add 1 to
						// it as current element is 1
						strg[r][c] = 1 + Math.min(strg[rp1][cp1], Math.min(strg[rp1][c], strg[r][cp1]));
					}
				}

				// if we have found a new square submatrix of size>omax, we update omax
				if (strg[r][c] > omax) {
					omax = strg[r][c];
					omaxRow = r;
					omaxCol = c;
				}
			}
		}

		// finally, we print the ans
		System.out.println("Size of maximum square submatrix : " + omax);
		System.out.println("Starting row : " + omaxRow);
		System.out.println("Starting column : " + omaxCol);

	}

}

// Time complexity analysis -

// The time complexity of the function will be O(n^2) where n is the size of the
// square matrix as we have to fill the whole 2d matrix for strg to find biggest
// square submatrix of all 1's starting
// at every position.

// Space complexity analysis -

// The extra space used by this algorithm is O(n^2) where n is the size of the
// square matrix as we made one 2d matrix strg.