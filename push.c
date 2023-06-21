#include "monty.h"

/**
 * add_node - add node to start of stack_t
 * @stack: head
 * @n: numb of new node
 *
 * Return: new node, if creation fails, NULL
 */
stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		return (NULL);
	}
	new->n = n;

	new->next = *stack;
	new->prev = NULL;
	if (*stack)
		(*stack)->prev = new;

	*stack = new;

	return (new);
}

/**
 *
 *
 *
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_stack;

	(void)line_number;
	
	if (is_number(global_n) != 0)
	{
		new_stack = add_node(stack, atoi(global_n));
		if (new_stack == NULL)
		{
			exit(EXIT_FAILURE);
		}
	}


	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}

