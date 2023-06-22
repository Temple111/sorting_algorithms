#include "sort.h"
#include "stdlib.h"

/**
 * counting_sort - sorts an array of integers in ascending order using the
 * Counting sort algorithm
 * @array: array to sort
 * @size: size of the array to sort
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int ai, max;
	int *count = NULL, *cpy = NULL;
	size_t bj, cp, total = 0;


	if (array == NULL || size < 2)
		return;
	cpy = malloc(sizeof(int) * size);
	if (cpy == NULL)
		return;
	for (bj = 0, max = 0; bj < size; bj++)
	{
		cpy[bj] = array[bj];
		if (array[bj] > max)
			max = array[bj];
	}
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(cpy);
		return;
	}
	for (ai = 0; ai <= max; ai++)
		count[ai] = 0;
	for (bj = 0; bj < size; bj++)
		count[array[bj]] += 1;
	for (ai = 0; ai <= max; ai++)
	{
		cp = count[ai];
		count[ai] = total;
		total += cp;
	}
	for (bj = 0; bj < size; bj++)
	{
		array[count[cpy[bj]]] = cpy[bj];
		count[cpy[bj]] += 1;
	}
	print_array(count, max + 1);
	free(count);
	free(cpy);
}
