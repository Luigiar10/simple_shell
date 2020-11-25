#include "shell.h"
char **tokenizador(char *line)
{
	char *word;
	int counter = 0;
	char **toks;
	char *delimiter = " ";

	toks = malloc(sizeof(char *) * 5);
	word = strtok(line, delimiter);
	while (word != NULL)
	{
		toks[counter] = _strdup(word);
		word = strtok(NULL, " ");
		counter++;
	}
	toks[counter] = word;

	return (toks);
}
/**
 * _strdup - function to copy an array with new memory address
 * @str: array to be copy
 * Return: the new array
 */
char *_strdup(char *str)
{
	char *p;
	unsigned int a = 0, len;

	if (str == NULL)
		return (NULL);
	len = _strlen(str);
	p = malloc(len + 1 * sizeof(char));
	if (p == NULL)
		return (NULL);
	for ( ; a < len; a++)
		p[a] = str[a];
	p[a] = str[a];
	return (p);
}
/**
 * _strlen - function to know the length of the string
 * @s: string
 * Return:  length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}