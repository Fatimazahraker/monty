#include "monty.h"

/**
 * is_number - checks if a string is a number
 * @str: the string
 * Return: 0 on success, and 1 otherwise
 */
int is_number(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			i++;

		if (str[i] < 48 || str[i] > 57)
			return (1);

		i++;
	}

	return (0);
}
