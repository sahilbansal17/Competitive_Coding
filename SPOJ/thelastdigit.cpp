#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
		int x,y,res=1;
		
		scanf("%d",&x);
		scanf("%d",&y);
		
		x=x%10;
		
		while(y>0)
		{
			if(y%2!=0)
			res=(res*x)%10;

			y=y/2;
			x=(x*x)%10;
		}
		
		printf("%d\n",res);
	}
	}