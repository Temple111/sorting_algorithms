#include "sort.h"

void swap_arr_ints(int *x, int *y);
int lomuto_partition_scheme(int *arr, size_t sz, int lt_side, int rt_side);
void lomuto_sort_scheme(int *arr, size_t sz, int lt_side, int rt_side);
void quick_sort(int *array, size_t size);

/**
 * swap_arr_ints - Swap two integers in an array.
 * @x: The first integer to swap.
 * @y: The second integer to swap.
 */
void swap_arr_ints(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * lomuto_partition_scheme - Order a subset of an array of integers according
 * to the lomuto partition scheme (last element as pivot).
 * @arr: The array of integers.
 * @sz: The size of the array.
 * @lt_side: The starting index of the subset to order.
 * @rt_side: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition_scheme(int *arr, size_t sz, int lt_side, int rt_side)
{
	int *pivot, up, down;

	pivot = arr + rt_side;
	for (up = down = lt_side; down < rt_side; down++)
	{
		if (arr[down] < *pivot)
		{
			if (up < down)
			{
				swap_arr_ints(arr + down, arr + up);
				print_array(arr, sz);
			}
			up++;
		}
	}

	if (arr[up] > *pivot)
	{
		swap_arr_ints(arr + up, pivot);
		print_array(arr, sz);
	}

	return (up);
}

/**
 * lomuto_sort_scheme - Implement the quicksort algorithm through recursion.
 * @arr: An array of integers to sort.
 * @sz: The size of the array.
 * @lt_side: The starting index of the array partition to order.
 * @rt_side: The ending index of the array partition to order.
 */
void lomuto_sort_scheme(int *arr, size_t sz, int lt_side, int rt_side)
{
	int part;

	if (rt_side - lt_side > 0)
	{
		part = lomuto_partition_scheme(arr, sz, lt_side, rt_side);
		lomuto_sort_scheme(arr, sz, lt_side, part - 1);
		lomuto_sort_scheme(arr, sz, part + 1, rt_side);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort_scheme(array, size, 0, size - 1);
}
