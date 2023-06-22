#define  _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"
global_param g_parm;

/**
 * main - entry point of the program
 * @argc: numb of command-line arg
 * @argv: array of command-line arg
 * Return: 0 on success, 1 otherwise
 */

int main(int argc, char **argv)
{
	size_t buf_size = 0;
	stack_t *stack = NULL;
	char *code = NULL;
	unsigned int numbr_line = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	g_parm.file = fopen(argv[1], "r");
	if (!g_parm.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", *argv);
		exit(EXIT_FAILURE);
	}
	while (getline(&g_parm.buffer, &buf_size, g_parm.file) != -1)
	{
		if (*g_parm.buffer == '\n')
		{
			numbr_line++;
			continue;
		}
		code = strtok(g_parm.buffer, "  \t\n");
		g_parm.global_n = strtok(NULL, "  \t\n");
		numbr_line++;
		executecode(&stack, code, numbr_line);
	}
	fclose(g_parm.file);
	free(g_parm.buffer);
	free_stack(stack);
	exit(EXIT_SUCCESS);
	return 0;
}
