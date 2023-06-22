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
    int temp;

    if (!stack || !*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    top1 = *stack;
    top2 = (*stack)->next;

    temp = top1->n;

    top1->n = top2->n;
    top2->n = temp;
}

/**
 * _add - adds the two top elements of the stack
 * @stack: a pointer to the first node of the stack
 * @line_number: the line number
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *current;


	current = *stack;

	*stack = current->next;
	(*stack)->n = (*stack)->n + current->n;
	(*stack)->prev = NULL;
	free(current);
}
