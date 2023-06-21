#include "monty.h"

/**
 *
 *
 *
 */

int main(int argc, char **argv)
{
	int file;
	size_t buf_size = 0;
	char *buffer = NULL;
	stack_t **stack = NULL;
	char *code = NULL;
	unsigned int numbr_line = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = open(argv[1], O_RDONLYI);
	if (file == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, buf_size, file) != -1)
	{
		if (*buffer == '\n')
		{
			nmbr_lin++;
			continue;
		}
		code = strtok(buffer, "  \t\n");
		arg = strtok(NULL, "  \t\n");
		executecode(&stack, code, numbr_line);
		numbr_line++;
	}
	close(file);
	free(buffer);
	exit(EXIT_SUCCESS);
}
