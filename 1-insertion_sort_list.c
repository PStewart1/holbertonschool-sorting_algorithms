#include "sort.h"

/**
 * swap - swaps 2 nodes
 * @back: previous node
 * @current: next node
 * Return: void
 */
void swap(listint_t *back, listint_t *current)
{
	listint_t *temp;

	temp = current;
	current->next = back->next;
	current->prev = back->prev;
	back->next = temp->next;
	back->prev = temp->prev;


}

/**
 * insertion_sort - sorts a doubly-linked list using Insertion Sort
 * @list: doubly-linked list of ints
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *head = *list;

	if (list == NULL)
		return;
	
	while (head)
	{
		current = head->next;
		while (current && current->prev && current->n < current->prev->n)
		{
			swap(current->prev, current);

			current = current->prev;
			print_list(*list);
		}
		
		head = head->next;
	}
}
