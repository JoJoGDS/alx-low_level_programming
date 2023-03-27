#include "main.h"
/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
	// Count the number of characters in the string
	int len = 0;
	while (*s != '\0') {
	len++;
	s++;
	}
	return len
}
