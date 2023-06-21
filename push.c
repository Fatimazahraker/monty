#include "monty.h"
/**
 *
 *
 *
 */

void push(stack_t **stack, unsigned int line_number)
{
	char n = global_n;
	stack_t *new_stack;
	
	if (is_digit(n)) != 0)
	{
		new_stack = add_node(stack, atoi(n));
		if (new_stack == NULL)
		{
			exit(EXIT_FAILURE);
		}
	}


	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_cnt);
		exit(EXIT_FAILURE);
	}
}

