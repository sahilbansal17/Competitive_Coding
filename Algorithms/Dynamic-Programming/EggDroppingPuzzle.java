//Suppose you have N eggs and you want to determine from which floor in a
//K-floor building you can drop an egg such that it doesn't break. You have
//to determine the minimum number of attempts you need in order to find the 
//critical floor in the worst case while using the best strategy. 
//There are few rules given below.

//An egg that survives a fall can be used again.
//A broken egg must be discarded.
//The effect of a fall is the same for all eggs.
//If the egg doesn't break at a certain floor, it will not break at any floor below.
//If the eggs breaks at a certain floor, it will break at any floor above.

//		Author - Aastha Aneja (Github handle - Aashu24)
//		Email - anejaaastha@gmail.com

import java.util.Scanner;

public class EggDroppingPuzzle {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);

		System.out.println("Enter number of eggs:");

		// no. of eggs
		int eggs = in.nextInt();

		System.out.println("Enter number of floors:");

		// no. of floors
		int floors = in.nextInt();

		// required function call
		System.out.println(eggDrop(eggs, floors));
	}

	// This function returns the min no. of drops that are guaranteed to find the
	// critical floor for a given no. of eggs and a given no. of floors
	public static int eggDrop(int eggs, int floors) {

		// This 2d array will store the min no. of egg drops required to find the
		// critical floor for e eggs and f floors in minDrops[e][f]
		int[][] minDrops = new int[eggs + 1][floors + 1];

		// We iterate over the 2d array
		for (int e = 1; e <= eggs; ++e) {

			for (int f = 1; f <= floors; ++f) {

				// if f=1, the minimum no. of trials will also be 1
				if (f == 1) {
					minDrops[e][f] = 1;
				}
				// if e=1, we will have to try and drop that egg from every floor till starting
				// from 1 to f which means min no. of trials will be f
				else if (e == 1) {
					minDrops[e][f] = f;
				}
				// if e>1 and f>1
				else {

					// this will give us overall min
					int minValue = Integer.MAX_VALUE;

					// we try and drop the egg from every kth floor
					for (int k = 1; k <= f; ++k) {

						// if the egg breaks at kth floor
						int eggBreaks = minDrops[e - 1][k - 1];

						// if the egg doesn't break at kth floor
						int eggSurvives = minDrops[e][f - k];

						// we consider the worst of these two cases
						int factor = Math.max(eggBreaks, eggSurvives);

						// and we find best of worsts using this value factor
						if (factor < minValue) {
							minValue = factor;
						}
					}

					// finally, we put the best of worsts value in minDrops[e][f]
					minDrops[e][f] = minValue + 1;
				}
			}
		}

		// The ans will be stored in minDrops[eggs][floors]
		return minDrops[eggs][floors];

	}

}

// Time complexity analysis -

// The time complexity of the function will be O(eggs*floors) as we have to fill
// the whole 2d matrix for minDrops to find minDrops for each possible value of
// eggs and floors.

// Space complexity analysis -

// The extra space used by this algorithm is O(eggs*floors) as we made one 2d
// matrix minDrops to store the min no. of drops.