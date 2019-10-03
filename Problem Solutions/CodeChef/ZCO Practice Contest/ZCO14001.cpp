#include <iostream>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	int a[n];

	for(int i=0; i<n; i++)
	{
		cin >> a[i];
	}

	int curr = 0;
	int flag = 0;

	int choice;
	cin >> choice;

	while(choice != 0)
	{
		switch(choice)
		{
			case 3:	if(!flag && a[curr])
					{
						flag = 1;
						a[curr]--;
					}
					break;

			case 4:	if(flag && a[curr] < k)
					{
						flag = 0;
						a[curr]++;
					}
					break;

			case 1:	if(curr > 0)
						curr--;
					break;

			case 2:	if(curr < n-1)
						curr++;
					break;
		}
		cin >> choice;
	}

	for(int i=0; i<n; i++)
		cout << a[i] << " ";
}
