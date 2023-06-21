#define  _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"
char *global_n;

/**
 *
 *
 *
 */

int main(int argc, char **argv)
{
	FILE *file;
	size_t buf_size = 0;
	char *buffer = NULL;
	stack_t *stack = NULL;
	char *code = NULL;
	unsigned int numbr_line = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", *argv);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &buf_size, file) != -1)
	{
		if (*buffer == '\n')
		{
			numbr_line++;
			continue;
		}
		code = strtok(buffer, "  \t\n");
		global_n = strtok(NULL, "  \t\n");
		executecode(&stack, code, numbr_line);
		numbr_line++;
	}
	fclose(file);
	free(buffer);
	free_stack(stack);
	exit(EXIT_SUCCESS);
	return 0;
}
