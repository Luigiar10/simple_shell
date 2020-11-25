#include "shell.h"

char *builtin(char *toks)
{
	int counter = 0;
	char *String;
	int i = 0;
	alias my_aliases[] = {
	{"/bin/ls", "/bin/ls"},
	{"/bin/ll", "/bin/ls -alF"},
	{"/bin/la", "/bin/ls -A"},
	{NULL, NULL},
	};

while (my_aliases[counter].alias_name != NULL)
	{
		if (_stdrup(toks, my_aliases[counter].alias_name) == 1)
		{
			toks = my_aliases[counter].real_name;
			String = malloc(sizeof(char) * 100);
			while (toks[i] != '\0')
			{
				String[i] = toks[i];
				i++;
			}
			return(String);
		}
		counter++;
	}

	return(toks);
}
int _stdrup(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	int k = 0;

	while (s1[i] != '\0')
	{ i++; }

	while(s1[j] != '\0')
	{
		if(s1[j] == s2[j])
		{
			k++;
		}
		j++;
	}
	if(k == i){
		return(1);
	}
	else
	{
		return (0);
	}
	return (0);
}