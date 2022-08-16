#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly-linked list using Insertion Sort
 * @list: doubly-linked list of ints
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node, *temp, *head;

	if (*list == NULL || (*list)->next == NULL)
		return;

	head = (*list)->next;
	while (head)
	{
		if (head->n < head->prev->n)
		{
			node = head;
			while (node->prev && node->n < node->prev->n)
			{
				temp = node->prev;
				temp->next = node->next;
				if (temp->prev != NULL)
					temp->prev->next = node;
				if (node->next != NULL)
					node->next->prev = temp;
				node->prev = temp->prev;
				node->next = temp;
				temp->prev = node;
				if (node->prev)
					(*list) = node;

				print_list(*list);
			}
		}
		head = head->next;
	}
}
