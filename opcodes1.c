#include "monty.h"

/**
 * sub -  substracts first two nodes of stack
 * @stack: stack
 * @line_numb: count lines
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_numb)
{
	int r;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_numb);
		exit(EXIT_FAILURE);
	}
	r = ((*stack)->next->n) - ((*stack)->n);
	pop(stack, line_cnt);
	(*stack)->n = r;
}

/**
 * mul - divide next value
 * @stack: stack
 * @line_numb: countt line
 *
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_numb)
{
	int r;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_numb);
		exit(EXIT_FAILURE);
		return;
	}

	r = ((*stack)->next->n) * ((*stack)->n);
	pop(stack, line_numb);
	(*stack)->n = r;
}
/**
 * pstr - print contents of stack_t
 * @stack: stack
 * @line_numb: count error messages
 *
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_numb __attribute__((unused)))
{
	stack_t *current = *stack;

	while (current)
	{
		if (current->n <= 0 || current->n > 127)
			break;
		putchar((char) current->n);
		current = current->next;
	}
	putchar('\n');
}
