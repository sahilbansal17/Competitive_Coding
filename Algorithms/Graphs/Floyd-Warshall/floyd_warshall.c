#include<stdio.h>
#include<stdlib.h>
//Name- Jyoti Mishra(@jstjyoti)
//E mail-jyotimishra29091997@gmail.com
/*Floyed Warshall algorithm is a algorithm which can give all possible shortest part from a given source vertex to a given destination vertex,
in a graph containing negative or positive weighted edges and not having any negative weight cycle(a cycle of graph resulting negative weight as whole)
Constraints for Simplifying The problems(assumed):
1)graph not having any negative weight cycle
2)adjacency matrix is chosen for 'n' number of vertices(n<=25 I have assumed can be changed by just making size of 2D-array of adjacency matrix)
*/
int n;//graph is having n vertices
int a[25][25];//the graph having <=25 vertices for sake of simplicity in understanding of implementation(n<=25) a[][] is adjacency matrix of the graph . vetices of graph are (0,1,2,..,n)
int p[25][25];//p is parent matrix having immediate parent of each vertex 
int d[10][10];//d is matrix having distance between nodes
/*create() function is for reading number of vertices and adjacency matrix of the graph. The vertices not having any vertex are maked as an infinitve(999)here.
Time complexity is O(n^2) and no extra variable is used so no space complexity.*/
void create()
{
	int i,j;
	printf("Input the number of vertices");
	scanf("%d",&n);
	printf("Input the \( %d x %d \) adjacency matrix of the graph",n,n);
	for(i = 1;i<= n;i++)
	{
		for(j=1;j<=n;j++)
		scanf("%d",&a[i][j]);
	}
}
/*This Function displays the graph in form of adjacency matrix
Time Complexity is O(n^2) as adjacency matrix is used for implementation*/
void showGraph(){
	int i;
	printf("\n The Graph is>>>>\n");
	for(i = 1;i<= n;i++)	
	{
		int j;
		for(j=1;j<=n;j++)
			printf("%4d",a[i][j]);
		printf("\n");
	}
}
/* the function floyedWarshall is actually manipulating and updating parent and distance array between all the vertices so that the min distance 
and parent for each vertex for that minimum distance and corrosponding parent is updated for all the vertices .
Time complexity of this is O(n^3) as there is all the distance and parents are updated for each vertex in 2nd k-i-j loop 
*/
void floyedWarshall()
{
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			d[i][j]=a[i][j];
			if((a[i][j]==0)||(a[i][j]==999))
			{
				p[i][j]=0;
			}
			else
				p[i][j]=i;
		}
	}
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(d[i][k]+d[k][j]<d[i][j])
				{
					d[i][j]=d[i][k]+d[k][j];
					p[i][j]=p[k][j];

				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(d[i][i]<0)
		{
			printf("\nNegative weight cycle >>>>can't be solved");
			exit(1);
		}
	}
}
/* APSP gives the path between vertex i and j depending upon the value p[][] and gives distance depending upon d[][] as updated by floyed washall algorithm
Time Complexity of this function is O(n) as there is a call until a parent exit i.e., there is a path and at most a path can have n vertices*/
void APSP(int i,int j)
{
	if(i==j)
		printf("\n%c(Distance %d)",i+64,d[i][i]);
	else if(p[i][j]==0)
	{
		printf("\n no paths possible from %c -> %c",i+64,j+64);
	}
	else
	{
		APSP(i,p[i][j]);
		printf("%c(distance %d)",j+64,d[i][j]);
	}
}
/*from main function after taking input and running floyedWarshall algorithm here I have Calculated All possible pairs of shortest path and distance 
by calling APSP() inside i,j loop for each pair of vertex(i and j) of the graph 
Since here the simpliest array(adjacency matrix ) representation of graph is chosen,therefore time complexity of overall algorithm is O(n^3)
The Time Complexity would have been differed depending upon number of vertices and edges if link representation of graph is used.*/
int main()
{
	int i,j;
	create();
	showGraph();
	floyedWarshall();
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			APSP(i,j);
		}
		printf("\n\n");
	}
	return 0;
}
