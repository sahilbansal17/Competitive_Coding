#include<stdio.h>
int main()
{
	//declaring a integer n
	int n;
	//scaning the value of that integer which will tell number of times we have to take input
	scanf("%d",&n);
	//declaring one more integer which will be used as counter 
	int k=0;
	//for loop because we have n line input
	for(int i=0;i<n;i++)
	{
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		if(x+y+z>=2)//our main condition
		{
			k++;//our counter
		}
	}
	printf("%d",k);//printing the count value which is our answer
	return 0;
}

