#include "shell.h"

/**
 * matchcommand - function to get the PATH env
 * @command: command to be match with the path
 * Return:  the PATH in a string.
 */
char *matchcommand(char *command)
{
	struct stat fileStat;



	if (*command == '.' || *command == '/')
		if (stat(command, &fileStat) == 0)
			return (command);
	

	return (command);
}

	int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
	{
		char *newline;
		int pid;
		int i = 0;
		char **toks;
		char *line;
		int int_mode = 0;
		size_t lineSize = 0;
		int charactersRead = 0;
		toks = malloc(sizeof(char *) * 5);

		while(int_mode < 9)
		{
			int_mode = isatty(STDIN_FILENO);
			if(int_mode == 1)
			{
				write(STDOUT_FILENO, "$", 1);
			}
			charactersRead = getline(&line, &lineSize, stdin);
			newline = malloc(sizeof(char) * 10);
			for (i = 0; line[i] != '\n'; i++)
			{
				newline[i] = line[i];
			}
			if (charactersRead == -1)
			{
				i = 0;
				while(toks[i] != '\0')
				{
					printf ("%s\n", toks[i]);
					free(toks[i]);
					i++;
				}
				free(toks);
				printf("\n");
				exit (98);
			}
			toks = tokenizador(newline);
			i = 0;
			while (toks[i] != '\0')
			{
				printf( "%s", toks[i]);
				i++;
			}
			pid = fork();
			if(!pid){

				pid  = execve(toks[0], toks, NULL);

				if (pid == -1) 
				{ 

					perror("Error printed by perror");
				} 
				else 
				{
					wait(NULL);
				}
			}	
}
		return (0);
	}

