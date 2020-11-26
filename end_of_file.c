#include "shell.h"


void end_of_line(int charactersRead,char **toks, char *newline, char *line)
{
	int i;
	if (charactersRead == -1)
			{
				i = 0;
				while(toks[i] != '\0')
				{
					free(toks[i]);
					i++;
				}
				free(newline);
				free(toks);
				free(line);
				printf("\n");
				exit (98);
			}
}

