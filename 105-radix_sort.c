#include "sort.h"
/**
 * radix_sort - sorts an array of integers in ascending
 * order
 *
 * @array: input array
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int flag = 1, num = 10;
	size_t ai, zf;

	if (!array || size == 1)
		return;
	while (flag)
	{
		flag = 0;
		for (ai = 1, zf = 1; ai <  size; ai++, zf++)
		{
			if ((array[ai - 1] % (num * 10)) / ((num * 10) / 10) > 0)
				flag = 1;
			if (((array[ai - 1] % num) / (num / 10)) > ((array[ai] % num) / (num / 10)))
			{
				array[ai - 1] = array[ai - 1] + array[ai];
				array[ai] = array[ai - 1] - array[ai];
				array[ai - 1] = array[ai - 1] - array[ai];
				if ((ai - 1) > 0)
					ai = ai - 2;
			}
		}
		print_array(array, size);
		num = num * 10;
	}
}
