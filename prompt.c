#include "shell.h"
/**
 * matchcommand - function to get the PATH env
 * @command: command to be match with the path
 * Return:  the PATH in a string.
 */
	int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
	{
		char *newline;
		int i = 0, int_mode = 0, charactersRead = 0, pid;
		char **toks, *line;
		size_t lineSize = 0;

		toks = malloc(sizeof(char *) * 5);
		while(int_mode < 9)
		{
			int_mode = isatty(STDIN_FILENO);
			if(int_mode == 1)
			{
				write(STDOUT_FILENO, "$", 1);
			}
			charactersRead = getline(&line, &lineSize, stdin);
			if (charactersRead == -1)
			{
				i = 0;
				while(toks[i] != '\0')
				{
					free(toks[i]);
					i++;
				}
				free(toks);
				printf("\n");
				exit (98);
			}
			if(*line == '\n')
			{
				continue;
			}
			newline = malloc(sizeof(char) * 10);
			for (i = 0; line[i] != '\n'; i++)
			{ newline[i] = line[i]; }
			newline = builtin(newline);
			toks = tokenizador(newline);
			pid = fork();
			if(!pid)
			{
				pid  = execve(toks[0], toks, NULL);
				if (pid == -1) 
				{ 
					perror("Error printed by perror");
				}
				else
				{ wait(NULL); }
			}
}
	return (0);
}
