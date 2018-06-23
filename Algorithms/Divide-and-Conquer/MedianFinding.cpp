#include<bits/stdc++.h>
using namespace std;
#define sz(a)	int(a.size())
#define pb 	 	push_back

// function for finding median
int findmedian (int array[], int size, int position)
{
	int partition = (size+4)/5;				//maximum number of partitions 
	std::vector<int> sublist[partition];
	int i,j;
	// dividing the array into partitions
	for (i = 0; i < size; i+=5)
	{
		for (j = i; j < i+5 && j < size; ++j)
		{
			sublist[i/5].pb(array[j]);				
		}
		sort(sublist[i/5].begin() ,sublist[i/5].end());
	}
	int median[partition];						// median stores the median of each partition
	
	for (i = 0; i < partition; ++i)
	{
		int size_of_sublist=sz(sublist[i]);
		median[i]=sublist[i][size_of_sublist/2];
	}
	int pivot;
	// finding pivot
	if(partition<=5)
	{
		// if size is small then sorting takes linear time so simply sort and find median
		sort(median,median+partition);
		pivot = median[(partition-1)/2];
	}
	else
	{
		//as size of median array is large find median of medians
		pivot = findmedian(median, partition, partition/2);
	}
	int low[size],high[size];
	int l=0, r=0, counter=0;
	// considering pivot as the approximate median divide the array into two subparts
	for (int i = 0; i < size; ++i)
	{
		if(array[i] < pivot)
		{
			low[l++] = array[i];
		}
		else if(array[i] > pivot)
		{
			high[r++] = array[i];
		}
		else 
		{
			counter++;
		}
	}
	// if position of pivot coincides with position of median return pivot
	if (position >= l && position< l+counter )
		return pivot;
	//if actual position of median is towards the left recurse to left
	else if (position < l)
		return findmedian(low, l, position);
	// if actual position of median is to the right recurse to the right
	else
		return findmedian(high, r, position-(l+counter));
}
int main()
{
	int n,array[101];
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>array[i];
	}
	/* Parameters : array, sizeofArray , k for finding kth smallest number
	In this case k=n/2 as median will be as n/2 th position */
	cout<<findmedian(array,n,n/2);
}