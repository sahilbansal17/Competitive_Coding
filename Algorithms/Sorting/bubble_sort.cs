using System;

namespace BubbleSort
{
    class Program
    {
        static void Main(string[] args)
        {
            //example
            int[] arr = { 1, 4, 3, 5, 8, 6, 0 };

            Bubblesort(arr);

            foreach (var item in arr)
            {
                Console.WriteLine(item);
            }
        }

        static void Bubblesort(int[] arr)
        {
            int n = arr.Length;

            for (int i = 0; i < n; i++)
                for (int j = 1; j < n - i; j++)
                    if (arr[j - 1] >arr[j])
                    {
                        int temp = arr[j - 1];
                        arr[j - 1] = arr[j];
                        arr[j] = temp;
                    }
        }
    }
}