#ifndef SHELLH
#define SHELLH
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
typedef struct aliases {
char *alias_name;
char *real_name;
} alias;
char *builtin(char *toks);
char *_strdup(char *str);
int _strlen(char *s);
int _stdrup(char *s1, char *s2);
char **tokenizador(char *line);
#endif