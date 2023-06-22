#include "sort.h"
/**
 * swap_num - swap two numbers
 * @x: integer
 * @y: integer
 **/
void swap_num(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}
/**
 * selection_sort - sort array using selection sort algorithm
 * @array: array
 * @size: array size
 **/

void selection_sort(int *array, size_t size)
{
	unsigned int ai, bj, min;

	if (array == NULL || size < 2)
		return;

	for (ai = 0; ai < size; ai++)
	{
		min = ai;
		for (bj = ai + 1; bj < size; bj++)
		{
			if (array[min] > array[bj])
				min = bj;
		}
		if (min != ai)
		{
			swap_num(&array[ai], &array[min]);
			print_array(array, size);
		}
	}

}
