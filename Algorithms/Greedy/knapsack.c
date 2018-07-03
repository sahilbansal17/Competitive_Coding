#include<stdio.h>
#include<stdlib.h>
/* Name: Jyoti Mishra
  E-mail:jyotimishra29091997@gmail.com(@jstjyoti)
SOME EXPLANATION ABOUT PROBLEM AND GREEDY APPROACH:
Greedy approach gives a solution for optimization Problem and always makes a choice which seems best at that moment and adds it to current subsolution . Final Output is optimal having maximum profit .
Greedy algorithm don't always yield optimal solution but,
when they do,they are usually the simplest and most efficient algorithms available.

the problems in fractional knapsack is to

--n items
--fraction of item i is taken to maximize profit unless the bag is full. Globally optimal choice is to take item with largest profit as p_i*(weight of object/weight remaining) and Greedy choice property for maximizing profit holds.
Dynamic Programming can solve Subproblems as well as overlapping Subproblems and finds a best solution by solving subproblems.

Fractional Knapsack can be solved using both Greedy algorithm and Dynamic Programming but 0-1 Knapsack can not be solved using greedy Algorithm because of following two key ingredient leading to DP solution,

0-1 Knapsack contains Optimal Substructure, an optimal solution to the problem contains within optimal solution of Subproblems.
Overlapping subproblems as same subproblem will be visited again and again (subproblem share sub-subproblem)
*/

int n;/*Number of objects given,a fraction object we are to choose and keep inside (x[]) knapsack having total weight  m */
struct Object
{	/*this is the structure defined for each object . Each 	object will have weight w, profit p, profit per unit 	weight f , and a char id(a single character name given to the object) 	assigned to object*/
	float w;
	float p;
	float f;
	char id;
};
typedef struct Object PW;
//profit(p) and weight(w) is all that we are concerned with .
PW *ptr;
//initilising a pointer to object Structure
/* The function Fractionalknapsack() gives the array showing how much fraction of each object will result an array saying what fraction of each object and total profit .
Time Complexity ofthis function is O(n) as there is only a for loop for one by one taking objects(sorted by profit per unit weight)*/
void Fractinalknapsack(float m)
{
	int i;
	float u,x[n],profit=0.0;
	for(i=1;i<=n;i++)
		x[i]=0.0;
	u=m;
	for(i=0;i<n;i++)
	{
		if(u<ptr[i].w)
			break;
		x[i]=1;
		u=u-ptr[i].w;
	}
	if(i<=n)
		x[i]=u/ptr[i].w;
	printf("Fraction\tId\tprofit\tWeight\n");
	for(i=0;i<n;i++)
	{
		printf("%0.2f\t\t %c\t %0.2f \t %0.2f\n",x[i],ptr[i].id,(ptr[i].p)*x[i],(ptr[i].w)*x[i]);
		profit+=ptr[i].p*x[i];
	}
	printf("\nTotal profit is %f",profit);

}
/*n objects are inputed(weight,profit of each object).Each object is given an id starting from A .
The objects are sorted according to profit per unit weight (any sorting algorithm can be used).Here I have used C STL Sorting Function qsort() for Simplicity .
Time Complexity of total program entirely depends upon the sorting algorithm as the complexity of greedy approach of Fractionalknapsack function is O(n).
Here,total complexity is O(nlogn) as the complexity is 
O(n^2)+O(n).*/
int main()
{
	PW tmp;
	float m;
	char c='A';
	printf("Enter the number of elements:\n");
	scanf("%d",&n);	
	ptr=(PW *)malloc(n*sizeof(PW));
	printf("Enter the weight of the elements:\n");
	int i,j;
	for(i=0;i<n;i++)
		scanf("%f",&ptr[i].w);
	printf("Enter the price of the elements:\n");
	for(i=0;i<n;i++)
		scanf("%f",&ptr[i].p);
	for(i=0;i<n;i++)
		ptr[i].id=c++;
	for(i=0;i<n;i++)
		ptr[i].f=(ptr[i].p/ptr[i].w);/*for profit per unit 			weight*/
	qsort(ptr,n,sizeof(*ptr),comparison_func);//objects are sorted as per profit per unit weight by C STL qsort() having average Complexity of O(nlogn)
	printf("Enter the total weight of the Knapsack:\n");
	scanf("%f",&m);
	Fractinalknapsack(m);
	
}


