#include "monty.h"

/**
 * free_stack - frees dlistint_t
 * @stack: head
 * Return: void
 */
void free_stack(stack_t *head)
{
	stack_t *current = head;
	stack_t *next;

	if (head)
	{
		next = head->next;
		while (current)
		{
			free(current);
			current = next;
			if (next)
				next = next->next;
		}
	}
}
