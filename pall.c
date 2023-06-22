#include "monty.h"

/**
 *pall - prints all the elmts of the stack
 * @stack: double ptr to the top of the stack
 * @line_number: line numb where the "pall" opcode appears
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	while(stack != NULL)
	{
		printf("%d\n", (*stack)->n);
		(*stack) = (*stack)->next;
	}
}
