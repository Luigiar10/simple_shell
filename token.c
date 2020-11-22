#include "shell.h"
char **tokenizador(char *line)
{
	char *token;
	int counter = 0;
	char **toks;

	toks = malloc(sizeof(char *) * 5);
token = strtok(line, " ");
while (token != NULL)
{
   toks[counter] = strdup(token);
   token = strtok(NULL, " ");
   counter++;
}
toks[counter] = token;

return (toks);
}