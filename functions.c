#include "monty.h"

/**
 * is_number - if string is a number
 * @str: string
 * Return: 0 on success, 1 otherwise
 */
int is_number(char *str)
{
	int s = 0;

	while (str[s])
	{
		if (s == 0 && (str[s] == '-' || str[s] == '+'))
			s++;

		if (str[s] < 48 || str[s] > 57)
			return (1);

		s++;
	}

	return (0);
}
