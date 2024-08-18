#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>

void display_prompt(void);
void get_input(char *lineptr, size_t len);

#endif
