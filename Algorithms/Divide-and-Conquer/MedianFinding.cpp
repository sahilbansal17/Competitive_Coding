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

 /* Complexity of the algorithm is O(n)
 At each step of the algorithm we do the following:
 -> Divide the array into partitions - O(n)
 -> Solve one subproblem for 1/5 of the size of original (Finding median of medians)
 -> Solve one subproblem for 7/10 of the size of original (Recursion part)
 	( This 7/10 can be tricky so I'll try explaining it. We select the pivot from the median of the partitions.Now in the worst
 	case we might select a pivot such that each partition with median less than pivot has all elements less than pivot and
 	each partition having median greater than pivot has 2 elements less than pivot. So the size of the array for the next
 	step of recursion can be (n/10)*5+(n/10)*2 = (7n/10) in the worst case. {(n/5)/2 partitions on both sides of pivot.} )
 So the reccurence for the algorithm is given by T(n) = T(n/5) + T(7n/10) + cn  .Try solving it using your preferred method
 to get the complexity of O(n).   
 
 But why partitions of 5 elements?
 Firstly ,computing median of an odd list is easier as we can simply select the middle element of the partition contrary to
 an even sized list in which we must take average of two middle elements.
 Also 5 is the smallest odd number for which median of median works. If we divide the array into partitions of size 3 then we
 get the reccurence T(n) = T(n/3) + T(2n/3) + cn solving which we get O(nlogn).Not so good! */
