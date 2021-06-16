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
	listint_t *prev_x = NULL, *next_y = NULL;

	if (x == NULL || y == NULL)
		return;

	prev_x = x->prev;
	next_y = y->next;

	if(prev_x != NULL)
		prev_x->next = y;
	else
		*list = y;

	if (next_y != NULL)
		next_y->prev = x;

	x->next = next_y;
	x->prev = y;
	y->next = x;
	y->prev = prev_x;
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
