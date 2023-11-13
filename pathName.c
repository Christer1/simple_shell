#include "techsol.h"

/**
 *fullPathname - output pathname if exit
 *@pathnames: all directory in path
 *@command: string of cmd
 *Return: NULL or full_pathname in str
 */

char *fullPathname(char *pathnames, char *command)
{
	char *tokenizer = NULL, **tokPath = NULL, *pathnameFull = NULL, *changed = NULL;
	int position = 0;
	size_t str_length = 0;

	if (pathnames == NULL)
		return (NULL);

	changed = strtok(pathnames, "=");
	changed = strtok(NULL, "=");

	tokPath = malloc(sizeof(char*) *30);
	if (tokPath == NULL)
	{
		free(pathnames);
		return (NULL);
	}

	tokenizer = strtok(changed, ":");
	while (tokenizer != NULL)
	{
		tokPath[position] = tokenizer;
		tokenizer = strtok(NULL, ":");
		position++;
	}

	tokPath[position] = NULL; /*ARRAY OF ALL DIRECTORIES*/
	position = 0;

	while (tokPath[position] != NULL)
	{
		str_length = strLen(tokPath[position]) + strLen(command) + 2;
		pathnameFull = malloc(str_length);
		strCpy(pathnameFull, tokPath[position]);
		strCat(pathnameFull, "/");
		strCat(pathnameFull, command);

		if (access(pathnameFull, X_OK) == 0)
		{
			free(tokPath);
			free(pathnames);
			return (pathnameFull);
		}

		free(pathnameFull);
		pathnameFull = NULL;
		position++;
	}

	free(tokPath);
	free(pathnames);
	return (NULL);
}

/**
 *strCat - concat two strs
 *@dest: first chara to conct
 *@src: second char to concat
 *Return: Return dest
 */

char *strCat(char *dest, char *src)
{
	int pos1;
	int pos2;

	pos1 = 0;

	while (dest[pos1] != '\0')
	{
		pos1++;
	}

	pos2 = 0;

	while (src[pos2] != '\0')
	{
		dest[pos1] = src[pos2];
		pos1++;
		pos2++;
	}

	dest[pos1] = '\0';

	return (dest);
}

/**
 *strCpy - copy str and return the dest
 *@dest: inputed val src
 *@src: inputed val src
 *Return: the destination
 */
char *strCpy(char *dest, char *src)
{
	int Pos = 0;

	int count = 0;

	while (*(src + Pos) != '\0')
		Pos++;
	for (; count < Pos; count++)
		dest[count] = src[count];

	dest[Pos] = '\0';
	return (dest);
}
