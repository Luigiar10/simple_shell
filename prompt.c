#include "shell.h"


	int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
	{
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
			toks = tokenizador(line);
			i = 0;
			while (toks[i] != '\0')
			{
				printf("%s", toks[i]);
				i++;
			}
			pid = fork();
			if (! pid) 
			{ 
				if (execve (toks[0], toks, NULL) == -1) 
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