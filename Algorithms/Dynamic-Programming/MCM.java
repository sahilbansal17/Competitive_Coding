	//Matrix Chain Multiplication

  public class fibonacci_dp {
	  
/*PROBLEM STATEMENT: Given a sequence of matrices, find the most efficient way to multiply these matrices together. 
The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications.
MCMBU is the function that applies bottom-up approach to solve the above problem.
1. Parameter passed to the function is in the form of array that contains the indices of the matrices to be multiplied.
like array { 40, 60, 20 } indicates two matrices ,first (40 X 60) and second (60 X 20)
2.it returns the optimized solution of the problem that is lowest number of operations to be peformed for above matrices.
*/
  public static int MCMBU(int[] arr) {
	  
	  /*declaring an array for bottom-up approach and initialising strg[j][j+1]=0
	  as i, j represents cost to multiply matrices from i to j in terms of number of operations.
	  matrices considered in j - j+1 would be single matrix 
	  number of operations=0;
	  */
	  
		int[][] strg = new int[arr.length][arr.length];

		for (int j = 0; j < arr.length - 1; j++) {
			strg[j][j + 1] = 0;
		}
	  

	  /*
	  using slide to consider each diagonal mid to upper-right.
	  si -Starting index of range being considered.
	  ei-Ending index of range being considered.
	  NOTE: lower-left matrix indices not taken into consideration as include opposite direction arr.length-1 -> 0.
	    
	  */
		for (int slide = 1; slide <= arr.length - 2; slide++) {
			int nts = arr.length - slide - 2;
			for (int si = 0; si <= nts; si++) {

				int ei = si + slide + 1;
				
  /* all possible computations are calculated and compared to find minimum number of operation case.*/
				int min = Integer.MAX_VALUE;
				for (int i = si + 1; i < ei; i++) {
					int ob = strg[si][i];
					int sb = strg[i][ei];

					int sw = arr[si] * arr[i] * arr[ei];
					int total = sw + ob + sb;
					if (min > total) {
						min = total;
					}
				}
				
  //The optimized solution of the subproblem si -> ei obtained is added to array strg.
				strg[si][ei] = min;

			}
		}
	  
	  //optimized solution obtained at top-right of array strg.
	  //returned the optimised solution obtained while considering all matrices from (0 -> arr.length-1)
		return strg[0][strg[0].length - 1];
	}
  
  public static void main(String[] args) {
   int[] arr = { 40, 60, 20,10 };
		 System.out.println(MCM(arr, 0, arr.length - 1, new int[arr.length][arr.length]));
     }
     }

//IMPORTANT: Do dry run to understand concept more clearly.
