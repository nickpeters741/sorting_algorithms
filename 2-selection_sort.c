#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: no return value (void)
 */
void selection_sort(int *array, size_t size)
{
	size_t idx, idx2;
	int temp = 0, idxtemp = 0, swap = 0;

	for (idx = 0; idx < size; idx++)
	{
		idx2 = idx + 1;
		temp = array[idx];
		while (idx2 < size)
		{
			if (temp > array[idx2])
			{
				temp = array[idx2];
				idxtemp = idx2;
				swap = 1;
			}
			idx2++;
		}
		if (swap == 1)
		{
			array[idxtemp] = array[idx];
			array[idx] = temp;
			print_array(array, size);
		}
		swap = 0;
	}
}
