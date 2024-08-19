#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define TOKEN_ARRAY_SIZE 20

void display_prompt(void);
char *get_input(char *lineptr, size_t len);
void string_tok(char *str, char *delim);

#endif
