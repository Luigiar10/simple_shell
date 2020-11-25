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
		toks[counter] = strdup(word);
		word = strtok(NULL, " ");
		counter++;
	}
	toks[counter] = word;

	return (toks);
}