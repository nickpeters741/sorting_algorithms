#include "sort.h"

/**
 * partition - find position of pivot element in array
 * @array: array to be sorted
 * @low: lower boundary of array
 * @hi: upper bound of array
 * @size: size of the array
 *
 * Return: position of pivot
 */
int partition(int *array, int low, int hi, size_t size)
{
	int pivot = array[hi], temp = 0, i = low, j = 0;
	(void)size;

	for (j = low; j <= hi; j++)
	{
		if (array[j] < pivot)
		{
			if ( i != j)
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != hi)
	{
		temp = array[i];
		array[i] = array[hi];
		array[hi] = temp;
		print_array(array, size);
	}
	return i;
}

/**
 * q_sort - sort a certain range of an array of integers
 * @array: array to be sorted
 * @low: lower boundary of range to be sorted
 * @hi: upper boundary of range to be sorted
 * @size: size of whole array
 *
 * Return: no return value (void)
 */
void q_sort(int *array, int low, int hi, size_t size)
{
	int part = 0;

	if (low < hi)
	{
		part = partition(array, low, hi, size);
		q_sort(array, low, part - 1, size);
		q_sort(array, part + 1, (size - part), size);
/*		print_array(array, size); */
	}
}

/**
 * quick_sort - sort an array of integers in ascending order
 * @array: pointer to first element of array to be sorted
 * @size: size of the array
 *
 * Return: no return value (void)
 */
void quick_sort(int *array, size_t size)
{
	int part = 0, low = 0, hi = size - 1;

	if (low < hi)
	{
		part = partition(array, low, hi, size);
		hi = part - 1;
		q_sort(array, low, hi, size);
		q_sort(array, part + 1, (size - part - 1), size);
/*		print_array(array, size); */
	}
}
