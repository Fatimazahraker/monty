#include "monty.h"

/**
 * free_stack - frees dlistint_t
 * @stack: head
 * Return: void
 */
void free_stack(stack_t *head)
{
	stack_t *current = head;

	if (head == NULL)
	{
		return;
	}
	while (head != NULL)
	{
		current = head->next;
		free(head);
		head = current;
	}
}
