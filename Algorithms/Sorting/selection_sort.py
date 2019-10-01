
def selectionSort(a):
	min_index = -1
	for i in range(len(a) - 1):
		min_index = i;
		for j in range(i + 1, len(a)):
			if(a[j] < a[min_index]):
				min_index = j
		a[min_index], a[i] = a[i], a[min_index]
	return a

arr = list(map(int, input("Enter the array elements: ").split()))
print(f"Array before sorting: {arr}")
arr = selectionSort(arr)
print(f"Array after sorting: {arr}")
