	#include <stdio.h>
	#include <unistd.h>
	#include <stdlib.h>

	int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
	{
		char *line;
		int int_mode = 0;
		size_t lineSize = 0;
		int charactersRead = 0;

		while(int_mode < 9)
		{
			int_mode = isatty(STDIN_FILENO);
			if(int_mode == 1)
			{
				write(STDOUT_FILENO, "$", 1);
			}
			charactersRead = getline(&line, &lineSize, stdin);
			if (charactersRead == -1){
				printf("\n");
				exit (98);
			}
		}
		return (0);
}