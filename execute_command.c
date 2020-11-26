#include "shell.h"


void excute_command (char **toks)
{
	int pid; 
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