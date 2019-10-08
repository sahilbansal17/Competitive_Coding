public class QuickSort_DualPivot {

	// quicksort the array a[] using dual-pivot quicksort
	public static void DualPivotQuickSort(int[] arr) {
		System.out.println("sa");
		Qsort(arr, 0, arr.length - 1);
	}

	// quicksort the subarray a[lo .. hi] using dual-pivot quicksort
	private static void Qsort(int[] Arr, int left, int right) {
		if (right - left >= 1) {
			if (Arr[left] > Arr[right]) {
				Utils.swap(Arr, left, right);
			}
			final int p = Arr[left];
			final int q = Arr[right];
			int l = left + 1, g = right - 1, k = l;
			while (k <= g) {
				if (Arr[k] < p) {
					Utils.swap(Arr, l, k);
					++l;
				} else if (Arr[k] >= q) {
					while (Arr[g] > q && k < g)
						--g;
					Utils.swap(Arr, g, k);
					--g;
					if (Arr[k] < p) {
						Utils.swap(Arr, l, k);
						++l;
					}
				}
				++k;
			}
			--l;
			++g;

			Utils.swap(Arr, l, left);
			Utils.swap(Arr, g, right);

			Qsort(Arr, left, l - 1);
			Qsort(Arr, l + 1, g - 1);
			Qsort(Arr, g + 1, right);
		}
	}

}
