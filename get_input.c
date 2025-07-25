#include "shell.h"

/**
* _getline - custom getline function
* @lineptr: pointer addr. to buffer containing line read from stream
* @n: size of buffer
* @stream: input source
* Return: number of chars read
*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t charcount = 0, new_size;
	int c;
	char *new_ptr = NULL;

	if (!lineptr || !n || !stream)
		return (-1);

	if (!*lineptr)
	{
		*lineptr = malloc(128);
		if (!*lineptr)
			return (-1);
		*n = 128;
	}

	while ((c = fgetc(stream)) != EOF)
	{
		if (charcount + 1 >= *n)
		{
			new_size = *n * 2;
			new_ptr = realloc(*lineptr, new_size);

			if (!new_ptr)
				return (-1);
			*lineptr = new_ptr;
			*n = new_size;
		}
		(*lineptr)[charcount++] = c;
		if (c == '\n')
			break;
	}

	if (charcount == 0 && c == EOF)
		return (-1);

	(*lineptr)[charcount] = '\0';
	return ((ssize_t)charcount);
}


/**
 * get_input - Gets input from the commandline
 *
 * Return: Void
 */
void get_input(void)
{
	ssize_t char_read;
	size_t len = 0;

	glob.input = NULL;
	char_read = _getline(&glob.input, &len, stdin);

	if (char_read == -1)
	{
		_free((void **)&glob.input);
		if (errno == 0)
			exit(EXIT_SUCCESS);
		else
			exit(EXIT_SUCCESS);
	}

	/*if (char_read > 0 && lineptr[char_read - 1] == '\n')*/
	/*{*/
	/*	lineptr[char_read - 1] = '\0';*/
	/*}*/
}
