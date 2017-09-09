//problem URL : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=54 

#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector < vector <int> > arr(51,vector <int>(51,0));

void mark(char dir,int &f)
{
	switch(dir)
	{
		case 'N':
			f=0;
			break;
		case 'S':
			f=2;
			break;
		case 'E':
			f=1;
			break;
		case 'W':
			f=3;
			break;
	}
}


void process(char p,int &f,int &x,int &y)
{
	if(p=='L')
	{
		f=(f+3)%4;
	}
	else if(p=='R')
	{
		f=(f+1)%4;
	}
	else
	{

		switch(f)
		{
			case 0:
				y++;
				break;
			case 1:
				x++;
				break;
			case 2:
				y--;
				break;
			case 3:
				x--;
				break;
		}
	}
}
int main()
{

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/CP_Sept/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/CP_Sept/output.txt","w",stdout);
	#endif

	int N,M;
	cin>>N>>M;

	//declaring a 2D array using dynamic memory allocation
	/*int *arr=new int*[n+1];
	for(int i=0;i<n;i++)
	{
		arr[i]=new int[m+1];
	}*/

	/*for(int i=0;i<=M;i++)
	{
		for(int j=0;j<=N;j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}*/
 	
 	int x,y;
 	char dir;
 	string code;
 	while(!cin.eof())
 	{
 		cin>>x>>y>>dir;
 		cin>>code;
 		//cout<<code<<endl;
 		
 		int len = code.length(),flag,lost=0;
 		mark(dir,flag);
 		for(int i=0;i<len;i++)
 		{
 			process(code[i],flag,x,y);
 			if(x>N)
 			{	
 				x--;
 				if(arr[x][y]==0)
 				{arr[x][y]=1;lost=1;break;}
 			}
			else if(y>M)
 			{
 				y--;
 				if(arr[x][y]==0)
 				{arr[x][y]=1;lost=1;break;}
 			}
 			else if(x<0)
 			{
 				x++;
 				if(arr[x][y]==0)
 				{arr[x][y]=1;lost=1;break;}
 			}
 			else if(y<0)
 			{	
 				y++;
 				if(arr[x][y]==0)
 				{arr[x][y]=1;lost=1;break;}
 			}
 		}
 		cout<<x<<" "<<y<<" ";
 		if(flag==0)
 			cout<<"N";
 		else if(flag==1)
 			cout<<"E";
 		else if(flag==2)
 			cout<<"S";
 		else
 			cout<<"W";
 		if(lost==1)
 		{
 			cout<<" LOST"<<endl;
 		}
 		else
 			cout<<endl;
 	}


}
