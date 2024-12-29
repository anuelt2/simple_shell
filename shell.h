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
#include <signal.h>

/**
* * Task 0 - 4 pass tests
* * Task 10 passes tests
* TODO-1: env/setenv/unsetenv might be ok. (Need to submit and see)
* TODO-2: implement getline and strtok
* TODO-3: Handling comments, files and variables
*/

#define TOKEN_ARRAY_SIZE 20
#define DELIM " \t\n"

/* Global variables */

/**
* struct Global - Holds globally used variables
* @environ_copy: copy of environ
* @input: glob.input from command line
* @comm_path: path of current command
*/
struct Global
{
	char **environ_copy;
	char *input;
	char *comm_path;
} glob;

/* shell.c */
void handle_sigint(int sig);

/* prompt.c */
void display_prompt(void);

/* get_input.c */
void get_input(void);

/* _free.c */
void _free(void **ptr);
void free_resources(char **args);

/* execute.c */
int exec_builtin(char *args[], char **envp);
void exec_external(char *comm, char *args[], char *envp[], int cmd_count);

/* exec_utils.c */
int _path_size(char **envp);
char *get_env_path(char **envp, int size);
char *_concatenate(char *dir, char *comm);
char *find_ext_file(char *comm, char **envp);

/* home_path_functions.c */
char *get_home_path(char **envp, int size);

int home_path_size(char **envp);

/* pwd_path_size */
char *get_pwd_path(char **envp, int size);
int pwd_path_size(char **envp);
char *get_oldpwd_path(char **envp, int size);
int oldpwd_path_size(char **envp);

/* cd_functions */
int cd_args(char **args, char **envp);

/* exit.c */
void exit_function(char *args[]);

/* cd_args.c */
int set_oldpwd(void);
int set_pwd(void);
int cd_exec(char *args[], char **envp);

/* str_utils.c */
size_t _strlen(char *str);
int _strcmp(char *str1, char *str2);
size_t _strncmp(char *str1, char *str2, size_t n);
char *_concat(char *var, char *val);
int _strcon(char *str, char c);

/* str_utils2.c */
char *_strcpy(char *dest, char *src);
char *_strdup(char *s);
char *_strcat(char *dest, char *src);
char **string_tok(char *str, char *delim);
char *format_env_var(char *name, char *value);

/* env_utils.c */
int env_size(void);
int get_env_size(char **env);
int get_env_var_value_len(char **env, char *var);
char *get_env_var_value(char **env, char *var);
char **copy_environ(void);

/* env_functions */
extern char **environ;
void get_env(void);
int set_env(char *var, char *val, int overwrite);
int unset_env(char *var);
int env_function_caller(char **args);

#endif
