#include "shell.h"

/**
 * *_memset - main
 *@s: pointer to the memory
 *@b: the byte to fill *s with
 *@n: the amount of bytes to be filled
 *Return: Always 0.
 */
char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;

for (i = 0; i < n; i++)
s[i] = b;
return (s);
}

/**
 * ffr - main
 * @pp: strings
 */
void ffr(char **pp)
{
char **a = pp;

if (!pp)
return;
while (*pp)
free(*pp++);
free(a);
}

/**
 * _realloc - main
 * @ptr: pointer
 * @old_size: byte
 * @new_size: byte
 *
 * Return: Always 0.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *p;

if (!ptr)
return (malloc(new_size));
if (!new_size)
return (free(ptr), NULL);
if (new_size == old_size)
return (ptr);

p = malloc(new_size);
if (!p)
return (NULL);

old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
p[old_size] = ((char *)ptr)[old_size];
free(ptr);
return (p);
}
