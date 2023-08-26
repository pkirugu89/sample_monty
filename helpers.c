#include "monty.h"
#include <ctype.h>

/**
 * is_numeric - converts string into an int
 * @str: string value to be checked
 * Return: an 1 if int, 0 otherwise
 */
int is_numeric(const char *str)
{
	/* Handle the case where the string is empty or NULL */
	if (str == NULL || *str == '\0')
	{
		return (0);
	}
	/* check each character in the string */
	while (*str != '\0')
	{
		/* checks if the current character is a digit */
		if (!isdigit(*str))
		{
			return (0);
		}
		str++; /* move to the next character */
	}
	return (1); /* is numeric */
}
