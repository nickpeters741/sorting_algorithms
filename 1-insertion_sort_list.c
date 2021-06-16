#include "sort.h"

/**
 * swap_node - swaps two nodes adjacent to one another
 * @list: pointer to head node of doubly linked list
 * @x: pointer to node to insert new node after
 * @y: node to be inserted after curr
 *
 * Return: no return value (void)
 */
void swap_node(listint_t **list, listint_t *x, listint_t *y)
{
	x->next = y->next;
	y->prev = x->prev;
	if (x->prev != NULL)
	{
		x->prev->next = y;
		x->prev = y;
	}
	else
	{
		*list = y;
		x->prev = y;
	}
	if (y->next != NULL)
	{
		y->next->prev = x;
	}
	y->next = x;
}

/**
 * insertion_sort_list - sorts a doubly linked list of ints in ascending order
 * @list: pointer to head node of the doubly linked list
 *
 * Return: no return value (void)
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *idx = NULL, *curr = NULL;

	curr = *list;
	if (list == NULL || curr == NULL || curr->next == NULL)
		return;

	while (curr != NULL)
	{
		idx = curr->prev;

		while (idx != NULL && idx->n > curr->n)
		{
			swap_node(list, idx, curr);
			print_list(*list);
			idx = curr->prev;
		}

		curr = curr->next;
	}
}
