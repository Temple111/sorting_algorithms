#include "sort.h"

void int_arr_swap(int *x, int *y);
void sort_bitonic_seq(int *arr, size_t sz, size_t start_id, size_t seq,
		char flow);
void convert_bitonic_seq(int *arr, size_t sz, size_t start_id,
		size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

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
 * sort_bitonic_seq - Sort a bitonic sequence inside an array of integers.
 * @arr: An array of integers.
 * @sz: The size of the array.
 * @start_id: The starting index of the sequence in array to sort.
 * @seq: The size of the sequence to sort.
 * @flow: The direction to sort in.
 */
void sort_bitonic_seq(int *arr, size_t sz, size_t start_id, size_t seq,
		char flow)
{
	size_t ai, jump = seq / 2;

	if (seq > 1)
	{
		for (ai = start_id; ai < start_id + jump; ai++)
		{
			if ((flow == UP && arr[ai] > arr[ai + jump]) ||
			    (flow == DOWN && arr[ai] < arr[ai + jump]))
				int_arr_swap(arr + ai, arr + ai + jump);
		}
		sort_bitonic_seq(arr, sz, start_id, jump, flow);
		sort_bitonic_seq(arr, sz, start_id + jump, jump, flow);
	}
}

/**
 * convert_bitonic_seq - Convert an array of integers into a bitonic sequence.
 * @arr: An array of integers.
 * @sz: The size of the array.
 * @start_id: The starting index of a block of the building bitonic sequence.
 * @seq: The size of a block of the building bitonic sequence.
 * @flow: The direction to sort the bitonic sequence block in.
 */
void convert_bitonic_seq(int *arr, size_t sz, size_t start_id,
		size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *st = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, sz, st);
		print_array(arr + start_id, seq);

		convert_bitonic_seq(arr, sz, start_id, cut, UP);
		convert_bitonic_seq(arr, sz, start_id + cut, cut, DOWN);
		sort_bitonic_seq(arr, sz, start_id, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, sz, st);
		print_array(arr + start_id, seq);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	convert_bitonic_seq(array, size, 0, size, UP);
}
