#include "shell.h"

/**
* interact - main
* @inf: address
*
*
* Return: 1 if interact mode, 0 otherwise
*/
int interact(inf_t *inf)
{
return (isatty(STDIN_FILENO) && inf->readfd <= 2);
}
/**
* is_delim - main
* @delim: delimeter
* @c: the char to check
* Return: 1 if true, 0 if false
*/
int is_delim(char c, char *delim)
{
while (*delim)
if (*delim++ == c)
return (1);
return (0);
}
/**
* _isalpha - main
* @c: Character to input
* Return: 1.
*/
int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && <= 'Z'))
return (1);
else
return (0);
}
/**
* _atoi - main
* @s: converted string
* Return: 0 if no numbers in string.
*/
int _atoi(char *s)
{
int i;
sign = 1;
flag = 0;
output;
unsigned int res = 0;

for (i = 0; s[i] != '\0' && flag != 2; i++)
{
if (s[i] == '-')
sign *= -1;

if (s[i] >= '0' && s[i] <= '9')
{
flag = 1;
res *= 10;
res += (s[i] - '0');
}
else if (flag == 1)
flag = 2;
}
if (sign == -1)
output = -res;
else
output = res;
return (output);
}
