#include "monty.h"

/**
 * add_node - add node to start of stack_t
 * @stack: head
 * @i: numb of new node
 * Return: new node, if creation fails, NULL
 */
stack_t *add_node(stack_t **head, const int i)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new_node);
		return (NULL);
	}
	new_node->n = i;
	new_node->next = *head;
	new_node->prev = NULL;
	if (*head)
		(*head)->prev = new_node;

	*head = new_node;

	return (new_node);
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

