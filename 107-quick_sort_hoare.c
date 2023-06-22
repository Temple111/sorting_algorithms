#include "sort.h"

void int_arr_swap(int *x, int *y);
int hoare_partition_scheme(int *arr, size_t sz, int left_side, int right_side);
void quicksort_algorithm(int *arr, size_t sz, int left_side, int right_side);
void quick_sort_hoare(int *array, size_t size);

/**
 * int_arr_swap - Swap two integers in an array.
 * @x: The first integer to swap.
 * @y: The second integer to swap.
 */
void int_arr_swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * hoare_partition_scheme - Order a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @arr: The array of integers.
 * @sz: The size of the array.
 * @left_side: The starting index of the subset to order.
 * @right_side: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int hoare_partition_scheme(int *arr, size_t sz, int left_side, int right_side)
{
	int pivot, above, below;

	pivot = arr[right_side];
	for (above = left_side - 1, below = right_side + 1; above < below;)
	{
		do {
			above++;
		} while (arr[above] < pivot);
		do {
			below--;
		} while (arr[below] > pivot);

		if (above < below)
		{
			int_arr_swap(arr + above, arr + below);
			print_array(arr, sz);
		}
	}

	return (above);
}

/**
 * quicksort_algorithm - Implement the quicksort algorithm through recursion.
 * @arr: An array of integers to sort.
 * @sz: The size of the array.
 * @left_side: The starting index of the array partition to order.
 * @right_side: The ending index of the array partition to order.
 */
void quicksort_algorithm(int *arr, size_t sz, int left_side, int right_side)
{
	int part;

	if (right_side - left_side > 0)
	{
		part = hoare_partition_scheme(arr, sz, left_side, right_side);
		quicksort_algorithm(arr, sz, left_side, part - 1);
		quicksort_algorithm(arr, sz, part, right_side);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_algorithm(array, size, 0, size - 1);
}
