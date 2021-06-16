#include "sort.h"

/**
 * parent - find parent element of given element
 * @i: element to find parent element of
 *
 * Return: parent element (int)
 */
int parent(int i)
{
	return ((i - 1) / 2);
}

/**
 * left_child - find left child element of given element
 * @i: element to find left child of
 *
 * Return: left child element (int)
 */
int left_child(int i)
{
	return ((2 * i) + 1);
}

/**
 * sift_down - repair heap to ensure each parent node is greater than its child
 * @array: array on which the heap neads to be repaired
 * @start: root position of the heap
 * @end: last element in the heap
 * @size: size of the array
 *
 * Return: no return value (void)
 */
void sift_down(int *array, int start, int end, size_t size)
{
	int root = start, l_child, r_child, swap, temp;

	while (left_child(root) <= end)
	{
		l_child = left_child(root);
		r_child = l_child + 1;
		swap = root;

/*
 * Check whether parent is less than left child
*/
		if (array[swap] < array[l_child])
			swap = l_child;
/*
 * Check whether parent is less than right child
*/
		if (r_child <= end && array[swap] < array[r_child])
			swap = r_child;
/*
 * Perform swap if needed, else return
*/
		if (swap == root)
		{
			return;
		}
		else
		{
			temp = array[root];
			array[root] = array[swap];
			array[swap] = temp;
			print_array(array, size);
			root = swap;
		}
	}
}

/**
 * heapify - put elements of array in heap order, in-place
 * @array: pointer to array to be heapified
 * @size: size of the array
 *
 * Return: no return value (void)
 */
void heapify(int *array, size_t size)
{
/*
 * start is assigned the index in array of the last parent node i.e. the parent
 * of the last element in the array
*/
	int start = parent(size - 1);

	while (start >= 0)
	{
		sift_down(array, start, size - 1, size);
		start -= 1;
	}
}

/**
 * heap_sort - sort an array of integers in ascending order using heap sort
 * @array: pointer to array to be sorted
 * @size: size of array
 *
 * Return: no return value (void)
 */
void heap_sort(int *array, size_t size)
{
	int end = size - 1, temp;

/*
 * Build the heap in array so that largest value is at the root
*/
	heapify(array, size);

/*
 * In the following loop, array[0:end] is a heap and
 * array[end:size] is in sorted order
*/
	while (end > 0)
	{
/*
 * array[0] is the root and is the largest element.
 * swap array[end] and array[0]
 */
		temp = array[end];
		array[end] = array[0];
		array[0] = temp;
		print_array(array, size);
		end -= 1;
/*
 * after each swap, heap size reduces so reduce end by 1
 * swap ruined the heap property, soo restore it suing siftdown function
*/
		sift_down(array, 0, end, size);
	}
}
