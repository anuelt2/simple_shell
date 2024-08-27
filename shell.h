#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>

#define TOKEN_ARRAY_SIZE 20
#define DELIM " \t\n"

void display_prompt(void);
char *get_input(char *lineptr, size_t len);
char **string_tok(char *str, char *delim);
int exec_builtin(char *args[], char **envp);
void exec_external(char *pathname, char *args[], char *envp[], int cmd_count);
char *get_env_path(char **envp, int size);
int _path_size(char **envp);
char *find_command(char *pathname, char **envp);
char *_concatenate(char *dir, char *pathname);
int is_executable(char *full_path);
char *find_ext_file(char *pathname, char **envp, int cmd_count);
char *get_home_path(char **envp, int size);
int home_path_size(char **envp);
char *get_pwd_path(char **envp, int size);
int pwd_path_size(char **envp);
char *get_oldpwd_path(char **envp, int size);
int oldpwd_path_size(char **envp);
int cd_args(char **args, char **envp);
void exit_function(char *args[]);
int set_oldpwd(void);
int set_pwd(void);
int cd_exec(char *args[], char **envp);

#endif
