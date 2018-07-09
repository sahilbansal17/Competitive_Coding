import java.util.Scanner;

public class Sudoku {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

    // Taking input ( if blank take is as Zero ) 
		int[][] arr = new int[9][9];
		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr[0].length; j++) {
				arr[i][j] = scanner.nextInt();
			}
		}

		int[] rows = new int[9];
		int[] cols = new int[9];
		int[][] submats = new int[3][3];

    // Here i will set the bit who values( from 1 to 9 ) are used in row , col and submats in given input   
		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr[0].length; j++) {
				rows[i] |= (1 << arr[i][j]);
				cols[j] |= (1 << arr[i][j]);
				submats[i / 3][j / 3] |= (1 << arr[i][j]);
			}
		}
		SolveSudoku(arr, 1, rows, cols, submats);
	}

	private static void SolveSudoku(int[][] arr, int cellNo, int[] rows, int[] cols, int[][] submats) {
  // Base case
		if (cellNo > arr.length * arr[0].length) {
    // Printing the solution 
			for (int i = 0; i < rows.length; i++) {
				for (int j = 0; j < cols.length; j++) {
					System.out.print(arr[i][j] + " ");
				}
				System.out.println();
			}
			return;
		}

    // Coverting 2D array to 1D arrray 
		int row = (cellNo - 1) / arr.length;
		int col = (cellNo - 1) % arr.length;
    
    // When value is already present  at any [row][col]
		if (arr[row][col] != 0) {
			SolveSudoku(arr, cellNo + 1, rows, cols, submats);
		} 
    
    // When value is zero at any [row][col]
    else {
			for (int choice = 1; choice <= 9; choice++) {
				if (isNumberAvailable(arr, rows, cols, submats, choice, row, col)) {
					reserveANumber(arr, rows, cols, submats, choice, row, col);
					SolveSudoku(arr, cellNo + 1, rows, cols, submats);
					releaseTheNumber(arr, rows, cols, submats, choice, row, col);
				}
			}
		}

	}

	private static boolean isNumberAvailable(int[][] arr, int[] rows, int[] cols, int[][] submats, int choice, int r,
			int c) {

    // Here I will set that bit which i choice( from 1 to 9 ) 
		int mask = 1 << choice;

    // Here I will do & to check whether this number is present or Not 
		if ((mask & rows[r]) != 0) {
			return false;
		} else if ((mask & cols[c]) != 0) {
			return false;
		} else if ((submats[r / 3][c / 3] & mask) != 0) {
			return false;
		} else {
			return true;
		}
	}

	private static void reserveANumber(int[][] arr, int[] rows, int[] cols, int[][] submats, int choice, int r, int c) {

     // Here I will set that bit which I keep at given index ( row , col ) and will do | to keep track of pre.  bit also  
     
		int mask = 1 << choice;
		arr[r][c] = choice;
    
		rows[r] |= mask;
		cols[c] |= mask;
		submats[r / 3][c / 3] |= mask;
	}

	private static void releaseTheNumber(int[][] arr, int[] rows, int[] cols, int[][] submats, int choice, int r,
			int c) {
    
    // Here I will free that number ( choice ). for that i will set choice bit as Zero and all 1. after that i will do & to get back all set bits.
    
    int mask = ~(1 << choice);
		arr[r][c] = 0;

		rows[r] &= mask;
		cols[c] &= mask;
		submats[r / 3][c / 3] &= mask;
	}
}
