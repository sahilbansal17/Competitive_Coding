// Name : Shivam Singhal
// Email ID : shivamsinghal0610@gmail.com
// Modified Knapsack algorithm to obtain maximum weight from an array that can be put 
// in a knapsack of given capacity with restricted number of weights to be taken

#include <iostream>
using namespace std;
 
struct node{
	int maxval;
	int maxitems;
};
 
// Prints the maximum value that can be put in a knapsack of capacity W
// such that the number of items taken is <= mit
void knapSack(int W, int wt[], int val[], int n, int mit)
{
	int i, w;
	node K[n+1][W+1];
	for (i = 0; i <= n; i++)
	{
		for (w = 0; w <= W; w++)
		{
			// initialising with 0 if number of items or weight in consideration is 0
			if (i == 0 || w == 0){
				K[i][w].maxval = 0;
				K[i][w].maxitems = 0;
			}
			// if weight of current item is <= knapsack capacity in consideration
			else if (wt[i-1] <= w){
				// deciding it current item is to be taken or not
           				if ((val[i-1] + K[i-1][w-wt[i-1]].maxval) > K[i-1][w].maxval){
           					// checking if max items limit is exceeded or not
           					if ((1 + K[i-1][w-wt[i-1]].maxitems) <= mit){
           						K[i][w].maxval = val[i-1] + K[i-1][w-wt[i-1]].maxval;
           						K[i][w].maxitems = 1 + K[i-1][w-wt[i-1]].maxitems;
           					}
           					else{
           						// selecting current item if it has max value
           						if (val[i-1] >= K[i-1][w].maxval && val[i-1] >= K[i-1][w-wt[i-1]].maxval){
           							K[i][w].maxval = val[i-1];
           							K[i][w].maxitems = 1;
           						}
           						else{
           							if (K[i-1][w].maxval > K[i-1][w-wt[i-1]].maxval){
           								K[i][w].maxval = K[i-1][w].maxval;
           								K[i][w].maxitems = K[i-1][w].maxitems;
           							}
           							else if (K[i-1][w].maxval < K[i-1][w-wt[i-1]].maxval){
           								K[i][w].maxval = K[i-1][w-wt[i-1]].maxval;

           								K[i][w].maxitems = K[i-1][w-wt[i-1]].maxitems;
           							}
           							else{
           								//selecting item which has minimum items taken already
           								if (K[i-1][w].maxitems <= K[i-1][w-wt[i-1]].maxitems){
           									K[i][w].maxval = K[i-1][w].maxval;
           									K[i][w].maxitems = K[i-1][w].maxitems;
           								}
           								else{
           									K[i][w].maxval = K[i-1][w-wt[i-1]].maxval;
           									K[i][w].maxitems = K[i-1][w-wt[i-1]].maxitems;
           								}
           							}
           						}
           					}
           				}
           				//not taking current item in knapsack
           				else if ((val[i-1] + K[i-1][w-wt[i-1]].maxval) < K[i-1][w].maxval){
            				K[i][w].maxval = K[i-1][w].maxval;
            				K[i][w].maxitems = K[i-1][w].maxitems;
           				}
           				else{
           					if (K[i-1][w-wt[i-1]].maxitems <= K[i-1][w].maxitems){ 
           						if ((1+K[i-1][w-wt[i-1]].maxitems) <= mit){
           							K[i][w].maxval = val[i-1] + K[i-1][w-wt[i-1]].maxval;
           							K[i][w].maxitems = 1 + K[i-1][w-wt[i-1]].maxitems;
           						}
           						else{
           							K[i][w].maxval = K[i-1][w].maxval;
           							K[i][w].maxitems = K[i-1][w].maxitems;	
           						}
           					}
           					else{
           						K[i][w].maxval = K[i-1][w].maxval;
           						K[i][w].maxitems = K[i-1][w].maxitems;
           					}
           				}
			}
			// if weight of current item exceeds knapsack weight in consideration, we simply take
			// the best case for 1 the items that have been checked already for the same knapsack capacity
			else{
            			K[i][w].maxval = K[i-1][w].maxval;
            			K[i][w].maxitems = K[i-1][w].maxitems;
			}
		}
	}
	int maxvalue = K[n][1].maxval, maxitem = K[n][1].maxitems; 
	for(i=2; i<=W; i++){
		if (K[n][i].maxval > maxvalue){
			maxvalue = K[n][i].maxval;
			maxitem = K[n][i].maxitems;
		}
	}
	for(i=1; i<=n; i++){
		if(K[i][W].maxval > maxvalue){
			maxvalue = K[i][W].maxval;
			maxitem = K[n][i].maxitems;
		}
	}
	cout<< "Maximum value possible : " << maxvalue << endl;
	cout<< "Number of items chosen : " << maxitem;
}
 
int main()
{
	int n, i, W, mit;
	cin >> n;
	cout << "Total number of elements : " << n << endl;
	int wt[n], val[n];
	for(i=0; i<n ; i++){
		cin >> wt[i] >> val[i] ;
	}
	cout << "Weights of each item : ";
	for(i=0; i<n ;i++)
		cout << wt[i] << " ";
	cout << endl;
	cout << "Values of corresponding item : ";
	for(i=0; i<n ;i++)
		cout << val[i] << " ";
	cout << endl;
	cin >> W >> mit ;
	cout << "Knapsack Capacity : " << W << endl;
	cout << "Number of items permissible : " << mit << endl;
	//function to calculate the maximum value obtainable taking items of total weight
	// <= W and number of items <= mit
	knapSack(W, wt, val, n, mit);
	return 0;
}

//We have created our DP table in such a way that for total number of items = n or knapsack capacity = w,
//the table contains the optimum value required. This is because we have already added conditions if each of the 
//items are to be added or not under given constraints of limited number of items and knapsack weight. If the number 
//of items taken for addition exceeds the total limit, then we either consider adding only that particular item, or 
//for lesser number of items with same knapsack weight or for lesser number of items with lesser knapsack weight. For 
// row = n or column = W, we have all possible values, and we only need to find the maximum of all these optimum values
//under different constraints.

// Time Complexity : O(nW)

//Our modified algorithm is nothing but a dp-based approach which stores tha maximum number of items possible
//such that kanpsack weight is not exceeded. It implements memoisation so we simply access previous values in
//O(1) time. Also, our algorithm is entirely composed of if-else statements, each of which take O(1) time. The 
//time complexity is therefore totally dependent on the 2 loops of n and W runtime each.

// Auxiliary Space Complexity : O(nW)
// This is because we consider taking a 2D array of size (n+1)*(W+1) for memoisation purposes. 
