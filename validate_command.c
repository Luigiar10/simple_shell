#include "shell.h"


char **validate_command(char *line,char *newline )
{
		int i;
		i = 0;
			for (i = 0; line[i] != '\n'; i++)
			{ 
				newline[i] = line[i];
			}
			newline = builtin(newline);
			return tokenizador(newline);

}