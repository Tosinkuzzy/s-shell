#include "main.h"
#include <stdio.h>

/**
* _printstring = Print string to stdout.
*
* Return: Always 0.
*/
int _printstring(char *str)
{
int i = 0, count = 0;

while (str[i])
{
count += _putchar(str[i++]);
}
return(count);
}
