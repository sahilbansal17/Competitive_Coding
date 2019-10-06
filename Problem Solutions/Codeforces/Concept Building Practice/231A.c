#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int k=0;
	for(int i=0;i<n;i++)
	{
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		if(x+y+z>=2)
		{
			k++;
		}
	}
	printf("%d",k);
	return 0;
}

