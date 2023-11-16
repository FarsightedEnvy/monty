#include "monty.h"
#include <stdlib.h>
#include <ctype.h>

/**
 * is_number - check if a string represents a number
 * @str: the string to check
 * Return: 1 if @str is a number, 0 otherwise
 */
int is_number(const char *str)
{
	int k = 0;

	if (str == NULL || *str == '\0')
		return (0);
	if (str[k] == '+' || str[k] == '-')
		k++;
	while (str[k] != '\0')
	{
		if (!isdigit(str[k]))
			return (0);
		k++;
	}
	return (1);
}
