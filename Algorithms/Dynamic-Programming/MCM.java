	//Matrix Chain Multiplication
  public class fibonacci_dp {

  public static int MCMBU(int[] arr) {
		int[][] strg = new int[arr.length][arr.length];

		for (int j = 0; j < arr.length - 1; j++) {
			strg[j][j + 1] = 0;
		}

		for (int slide = 1; slide <= arr.length - 2; slide++) {
			int nts = arr.length - slide - 2;
			for (int si = 0; si <= nts; si++) {

				int ei = si + slide + 1;

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

				strg[si][ei] = min;

			}
		}
		return strg[0][strg[0].length - 1];
	}
  
  public static void main(String[] args) {
   int[] arr = { 40, 60, 20 };
		 System.out.println(MCM(arr, 0, arr.length - 1, new int[arr.length][arr.length]));
     }
     }
