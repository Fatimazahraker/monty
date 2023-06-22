#include "monty.h"

/**
 *pall - prints all the elmts of the stack
 * @stack: double ptr to the top of the stack
 * @line_number: line numb where the "pall" opcode appears
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *stack1;

	(void)line_number;

	if (stack == NULL || *stack == NULL)
		return;

	stack1 = *stack;

	while(stack1 != NULL)
	{
		printf("%d\n", stack1->n);
		stack1 = stack1->next;
	}
}
