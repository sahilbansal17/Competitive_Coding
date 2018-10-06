#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
int main()
{
	int t,i,j,n,q;long long a,b,p=-1;
	scanf("%d",&q);
	int fl=0;
	double m=0;long long s=0;
	vector<long long > v;
	for(i=0;i<q;i++)
	{
		cin>>a;
		if(a==1)
		{
			cin>>b;
			v.push_back(b);	
		}
		else
		{
			if(fl==0)
			{
				s+=v[0];
				p=0;
				fl=1;
			}
			
			if(v.size()==1)
			{
				printf("0.0000000\n");
			}
			else
			{
				s+=v[v.size()-1];
				m=double(s)/(p+2);
				for(j=p+1;j<v.size()-1;j++)
				{
					if(v[j]<=m)
					{
						s+=v[j];
						p++;
						m=double(s)/(p+2);
					}
					else
						break;
				}
				printf("%.7llf\n",double(v[v.size()-1])-m);
				s-=v[v.size()-1];
			}	
			fl=1;
		}
	}
}

