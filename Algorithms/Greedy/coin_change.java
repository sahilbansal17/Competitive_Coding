
//		Coin Problem Description -
//		Given a value V, if we want to make change for the amount V and
//		we have infinite supply of each of the denominations in some
//		currency say {1,2,5,10,20,50} (which will be taken as input from the user}
//		valued coins/notes, what is the minimum number of coins and/or notes
//		needed to make the change?
//
//		Author - Aastha Aneja (Github handle - Aashu24)
//		Email - anejaaastha@gmail.com
		
import java.util.Arrays;
import java.util.Scanner;

public class CoinProblem {

	public static void main(String[] args) {

		// Scanner declaration to take input
		Scanner in = new Scanner(System.in);

		System.out.println("Enter the number of distinct coin denominations:");
		// This variable is for the size of coin array
		int coin_size = in.nextInt();

		// This array is to take input of the values of various denominations of coins
		// available
		int[] coins = new int[coin_size];

		System.out.println("Enter the "+coin_size+" denomination values:");
		
		// This loop is to take input in the coins array for different denominations
		for (int i = 0; i < coin_size; i++) {
			coins[i] = in.nextInt();
		}

		System.out.println("Enter the value for which change is to be made:");
		
		// This variable is to take input of a value whose change we want to make
		int value = in.nextInt();

		System.out.println("Greedy solution:");
		// Calling the function that applies a Greedy algorithm for the solution
		coinChangeGreedy(coins, value);

		System.out.println("Dynamic Programming solution:");
		// Calling the function that applies a Dynamic programming algorithm for the
		// solution
		coinChangeDP(coins, value);
	}

	
	
	
	// This function solves the Coin change problem using a Greedy approach
	// The Greedy approach simply starts from the largest coin denomination
	// and moves to the smallest coin denomination checking if that denomination
	// is required to make change for the value and if it is required, then the
	// the value (for which change is to be made) is decremented (or updated) by the
	// amount used of that coin denomination.
	public static void coinChangeGreedy(int[] coins, int value) {

		// This statement sorts the coins array in ascending order
		Arrays.sort(coins);

		// This is the index of the biggest element in the coins array i.e. the biggest
		// denomination of coin we have
		int index = coins.length - 1;

		// This variable stores the minimum no. of coins required initially 0
		int min_coins_required = 0;

		// This loop runs till the value whose change we want to make doesn't become
		// zero and the index>=0 (so that the coins array doesn't go out of bounds)
		while (value != 0 && index >= 0) {

			// This takes up one value of the coin denomination starting from the largest
			// and moving to the smaller ones
			int coin_denomination = coins[index];

			// This statement counts the no. of coins required of that particular coin
			// denomination to reach to the value
			int count = value / coin_denomination;

			// This condition will run only if we need that denomination to make the change
			if (count != 0) {

				// This updates the min_coins_required by adding the number of coins of this
				// denomination to already existing min_coins_required
				min_coins_required = min_coins_required + count;

				// This updates the value by taking its remainder with the coin_denomination
				value = value % coin_denomination;
			}

			// This updates the index to consider the next largest coin denomination
			index--;
		}

		// Statement to print the minimum number of coins required to make change for
		// the value
		System.out.println(min_coins_required);
	}
	
	
	

	// The DP approach takes an array to store min number of coins required to make
	// change for amounts from 0 to given value and then checks if it can reduce the
	// number of coins for every value by taking into consideration every coin that
	// has a value less than the amount we want to make change for
	public static void coinChangeDP(int[] coins, int value) {
		// This array will store the minimum number of coins required to make change for
		// amounts from 0 to value
		int[] min_coins_required = new int[value + 1];

		// This loop stores changes the initial value of min_coins_required for amount 0
		// to value to the Max value of Integer or infinity
		for (int index = 1; index <= value; index++) {
			min_coins_required[index] = Integer.MAX_VALUE;
		}

		// As minimum amount of coins required to make change for value=0 is 0, we run
		// this loop from 1 to value to compute min_coins_required for amounts 1 to
		// value
		for (int v = 1; v <= value; v++) {

			// This loop checks the result for each coin value smaller than the amount we
			// want to make change for
			for (int cntr = 0; cntr < coins.length; cntr++) {

				// fetching value of current coin or coin at index cntr
				int coin = coins[cntr];

				// If the value of this coin is less than or equal to the amount
				if (coin <= v) {

					// Min coins required for this value will be (for this coin) +
					// min_coins_required to make change for (this amount - value of this coin)
					int min_coins = 1 + min_coins_required[v - coin];

					// If new min number of coins is less than the already stored value, we update
					// the value in the DP array of min_coins_required
					if (min_coins < min_coins_required[v]) {
						min_coins_required[v] = min_coins;
					}
				}
			}
		}

		// This statement prints the final result
		System.out.println(min_coins_required[value]);
	}
}


//
// Time complexity of Greedy solution :
//
// Assuming that the coin denominations array given to us is already sorted, the
// time complexity of the Greedy solution will be O(n) in the worst case where n
// is the size of the coin denominations array. The worst case will be when we
// have to use each and every coin in the given coin denominations array to make
// the change for the given value and hence we will have to traverse the whole
// coin denominations array once and this will make its time complexity O(n).
//
//
// Time complexity of Dynamic Programming solution :
//
// The time complexity of the DP solution will be O(value*size of coins array).
// This is because we will have to fill the whole min_coins_required array for
// each amount from 0 to value and to do that we will have to consider every
// possible coin denomination that is available to us.
//
//
// Space complexity of Greedy solution :
//
// The space complexity of Greedy solution will be O(n) where n is the size of
// the coins array since we only have to store the coins array and no extra
// significant memory is required to reach the solution.
//
//
// Space complexity of Dynamic Programming solution :
//
// The space complexity of DP solution will be O(n+value) where n is the size of
// the coins array and value is the amount we wish to make change for. This is
// so because in the DP solution, we have to take up extra space to store the
// min_coins_required array that stores the number of minimum coins required to
// make change for amounts from 0 to value. Assuming that value>n, the space
// complexity becomes O(value).
//
//
// Why Greedy solution doesn't work for all possible cases?
//
// Eg.- If we are given a value = 30 to make change using coin denominations =
// {1,10,25}, the Greedy solution will give the answer 6 for minimum number of
// coins because it will consider one Rs.25 coin and five Rs.1 coins. However,
// we can also make this change using three coins of Rs.10 which is a better
// solution as it uses lesser number of coins. The DP approach will give us this
// correct solution.
//
// There are many ways to make change for a given value using a set of coins.
// For eg.- for the case given above, some of the possible solutions can be
// {10,10,10}, {1,1,....(30times)}, {10,10,1,1,1,1,1,1,1,1,1,1,} and so on. The
// Greedy solution does not consider all of these possible solutions. This is
// because the Greedy algorithm starts working from the largest coin
// denomination that is just smaller than the required value and then moves to
// the smaller values and repeats the same steps over and over again until the
// value becomes zero. It considers only some of the possible cases. However,
// the DP approach considers making change using all these possibilities and
// then checks if the new solution is better than its current solution and if it
// is better, then it updates the solution in the min_coins_required array. So,
// the Greedy algorithm gives us a suboptimal solution.
//
// So, when does the Greedy solution actually work?
// The Greedy solution gives us an optimal solution for canonical coin systems.
// A coin system is canonical if the number of coins given in change by the
// greedy algorithm is optimal for all amounts. For a non-canonical coin system,
// there is an amount c for which the greedy algorithm produces a suboptimal
// number of coins; c is called a counterexample. A coin system is tight if its
// smallest counterexample is larger than the largest single coin. The paper
// https://graal.ens-lyon.fr/~abenoit/algo09/coins2.pdf
// elaborates more on canonical coin systems and also gives an O(n^3) algorithm
// to determine if the given coin system is canonical or not.