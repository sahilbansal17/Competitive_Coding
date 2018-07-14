#include <iostream>
#include <vector>
using namespace std;

const int L = 1e5 + 7;
int arr[L];

void countingSort(int place, int number_of_elements)
{
	std::vector<int> buckets[10];
	int digit;
	for (int i = 0; i < number_of_elements; ++i)
	{
		digit = (arr[i] / place) % 10;
		// elements of arr are divided into buckets based on the digit at current place
		buckets[digit].push_back(arr[i]);
	}
	int idx = 0;
	
	// Starting from the first bucket elements are placed into the base Array as the elements
	// in bucket having smaller index would be smaller(considering only digits upto the current place)
	// Also elements in the same bucket will be in increasing order on the basis of digit at place-1
	// This way elements in arr will be sorted on the basis of digits upto the current place
	for (int i = 0; i < 10 ; ++i)
	{
		for (auto &x : buckets[i])
		{
			arr[idx++] = *it;
		}
	}
	return;
}
void radixSort(int number_of_elements, int max_element)
{
	// place represents the current place in the number
	int place = 1;
	while(max_element > 0)
	{
		// calling countingSort function for current place 
		countingSort(place, number_of_elements);
		// updating value of place for next iteration
		place *= 10;
		// the maximum number of places in any number in the array = log10(max_element)
		// This loop would run log10(max_element) times as in each iteration max_element
		// is divided by 10
		max_element /= 10;
	}
	return;
}
int main()
{
	int number_of_elements, max_element;
	cout << "Enter number of elements = ";
	cin >> number_of_elements;
	cout << "Enter elements ";
	
	for (int i = 0; i < number_of_elements; ++i)
	{
		cin >> arr[i];
		// finding the maximum element in the input array
		max_element = max(max_element, arr[i]);
	}

	radixSort(number_of_elements, max_element);
	
	for (int i = 0; i < number_of_elements; ++i)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
// Radix sort is quite similar to sorting strings lexicographically. Out of any two string, one having larger
// character at the first point of difference would be lexicographically greater.
// We can extend this to integers if we pad up all integers with 0s to its left such that each has the same 
// number of digits.
// So what we do in radix sort is we start from the LSD and sort each number on the basis of the digit at current
// place using counting sort. We move from LSD to MSD and eventually the array is sorted.

// Time Complexity : O(nk) where k is the number of digits in the max_element
//                   The loop inside radixSort function runs k = log10(max_element) times.In each iteration
//                   of the loop countingSort function is called, whose complexity is O(n) as the loop inside countingSort 
//                   runs n times. So overall complexity of the algorithm is O(nk).
// Space Complexity : O(n) 
//                    10 vectors are created in each iteration which store a total of n elements. So total space
//                    required is O(n).

// The time complexity of counting sort is O(n+k) where k is the maximum element of the array. If k is significantly
// large then radixSort can be used instead of counting sort.
// When log(n) is significantly larger than k then radix sort can be used instead of nlog(n) sorting algoritms.