#include<stdio.h>
#include<stdlib.h>
int n;
int a[10][10];
int p[10][10];
int d[10][10];
void create()
{
	int i;
	FILE *fp;
	fp = fopen("apsp.txt","r");
	if(fp==NULL)
	{
		printf("File open failed");
		exit(0);
	}
	fscanf(fp,"%d",&n);
		
	for(i = 1;i<= n;i++)
	
	{
		int j;
		for(j=1;j<=n;j++)
		fscanf(fp,"%d",&a[i][j]);
	}
	
	fclose(fp);
}

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
	
