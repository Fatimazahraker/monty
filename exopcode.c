#include "monty.h"

/**
 * executecode - Executes the corresponding instruction based on the opcode
 * @stack: double pointer to the top of the stack
 * @str: to be executed
 * @line_number: where the opcode appears
 * Return: void
 */

void executecode(stack_t **stack, char *str,unsigned int line_number)
{
	instruction_t inst[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	int i = 0;

	while (inst[i].opcode != NULL)
	{
		if (strcmp(inst[i].opcode, str) == 0)
		{
			inst[i].f(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, str);
	exit(EXIT_FAILURE);
}

