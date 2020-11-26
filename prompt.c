#include "shell.h"
/**
 * matchcommand - function to get the PATH env
 * @command: command to be match with the path
 * Return:  the PATH in a string.
 */
	int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
	{
		char *newline;
		int int_mode = 0, charactersRead = 0;
		char **toks, *line;
		size_t lineSize = 0;

		newline = malloc(sizeof(char) * 10);
		toks = malloc(sizeof(char *) * 5);
		while(int_mode < 9)
		{
			int_mode = isatty(STDIN_FILENO);
			if(int_mode == 1)
			{
				write(STDOUT_FILENO, "$", 1);
			}
			charactersRead = getline(&line, &lineSize, stdin);
			end_of_line(charactersRead, toks, newline, line);
			if(*line == '\n')
			{
				continue;
			}
			toks = validate_command(line, newline);
			excute_command(toks);
}
	return (0);
}
