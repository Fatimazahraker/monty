#include "monty.h"

/**
 * is_number - if string is a number
 * @str: string
 * Return: 0 on success, 1 otherwise
 */
int is_number(char *string)
{
	int s = 0;

	if (string == NULL)
		return (1);

	while (string[s])
	{
		if (s == 0 && (string[s] == '-' || string[s] == '+'))
			s++;

		if (string[s] < '0' || string[s] > '9')
			return (1);

		s++;
	}

	return (0);
}
