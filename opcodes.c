#include "monty.h"

/**
 * pop - pops the top element of the stack
 * @stack: stack
 * @line_number: line numb
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	if (!*stack)
		return;
	(*stack)->prev = NULL;
}

/*--------------------pint--------------------------*/
/**
 * pint - prints the value at the top of the stack
 * @stack: stack
 * @line_number: line numb
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}
/*---------------------swap-------------------------*/
/**
 * swap - swaps the top two elements of the stack
 * @stack: stack
 * @line_number: line numb
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *top1, *top2;

    if (!stack || !*stack || !(*stack)->n)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    top1 = *stack;
    top2 = (*stack)->n;

    top1->prev = top2;
    top1->n = top2->n;

    if (top2->n)
        top2->n->prev = top1;

    top2->prev = NULL;
    top2->n = top1;

    *stack = top2;
}

