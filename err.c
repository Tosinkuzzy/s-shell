#include "shell.h"
/**
* _eputs - main
* @ptr: string
*
* Return: Always 0.
*/
void _eputs(char *ptr)
{
int i = 0;

if (!ptr)
return;
while (ptr[i] != '\0')
{
_eputchar(ptr[i]);
i++;
}
}
/**
* _eputchar - main
* @c: character
*
* Return: Always 0.
*/
int _eputchar(char c)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(2, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}
/**
* _putfd - main
* @c: character
* @fd: file descriptor
*
* Return: Always 0.
*/
int _putfd(char c, int fd)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_flush || i >= WRITE_BUF_SIZE)
{
write(fd, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}
/**
* _putsfd - main
* @ptr: string
* @fd: file descriptor.
*
* Return: Always 0.
*/
int _putsfd(char *ptr, int fd)
{
int i = 0;

if (!ptr)
return (0);
while (*ptr)
{
i += _putfd(*ptr++, fd);
}
return (i);
}
