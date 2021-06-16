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
	int pivot = array[hi], temp, i = low - 1, j;

	for (j = low; j <= hi; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
		}
	}
	return (i);
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
		q_sort(array, part + 1, hi, size);
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
	if (size < 2)
		return;

	q_sort(array, 0, size - 1, size);
}
