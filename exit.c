#include "shell.h"

/**
* *_strchr - main
* @s: string
* @c: character.
* Return: Always 0.
*/
char *_strchr(char *s, char c)
{
do {
if (*s == c)
return (s);
} while (*s++ != '\0');
return (NULL);
}
/**
* *_strncpy - main
* @dst: location of string to copy.
* @sc: source
* @n: total
* Return: Always 0.
*/
char *_strncpy(char *dst, char *sc, int n)
{
int i, j;
char *s = dst;

i = 0;
while (sc[i] != '\0' && i < n - 1)
{
dst[i] = sc[i];
i++;
}
if (i < n)
{
j = i;
while (j < n)
{
dst[j] = '\0';
j++;
}
}
return (s);
}
/**
* *_strncat - main
* @dst: F string
* @sc: S string
* @n: total bytes
* Return: Always 0.
*/
char *_strncat(char *dst, char *sc, int n)
{
int i, j;
char *s = dst;

i = 0;
j = 0;
while (dst[i] != '\0')
i++;
while (sc[j] != '\0' && j < n)
{
dst[i] = sc[j];
i++;
j++;
}
if (j < n)
dst[i] = '\0';
return (s);
}

