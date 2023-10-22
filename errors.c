#include "shell.h"

/**
* _err_atoi - main
* @s: string
*
* Return: Always 0.
*/
int _err_atoi(char *s)
{
int i = 0;
unsigned long int res = 0;

if (*s == '+')
s++;
for (i = 0; s[i] != '\0'; i++)
{
if (s[i] >= '0' && s[i] <= '9')
{
res *= 10;
res += (s[i] - '0');
if (res > INT_MAX)
return (-1);
}
else
return (-1)
}
return (res);
}
/**
* p_error - main
* @inf: param struct
* @eptr: string
*
* Return: Always 0.
*/
void p_error(info_t *info, char *eptr)
{
_eputs(info->fname);
_eputs(": ");
p_d(info->line_count, STDERR_FILENO);
_eputs(": ");
_eputs(info->argv[0]);
_eputs(": ");
_eputs(eptr);
}
/**
* p_d - main
* @ipt: input
* @fd: file descriptor
*
* Return: Always 0.
*/
int p_d(int ipt, int fd)
{
int (*__putchar)(char) = _putchar;
int i, ct = 0;
unsigned int _abs_, crrt;

if (fd == STDERR_FILENO)
__putchar = _eputchar;
if (ipt < 0)
{
_abs_ = -ipt;
__putchar('-');
ct++;
}
else
_abs_ = ipt;
crrt = _abs_;
for (i = 1000; i > 1; i /= 10)
{
if (_abs_ / i)
{
__putchar('0' + crrt / i);
ct++;
}
crrt %= i;
}
__putchar('0' + crrt);
ct++;

return (ct);
}
/**
* c_no - main
* @no: number
* @be: base
* @flags: arguemnt flags
*
* Return: Always 0.
*/
char *c_no(long int no, int be, int flags)
{
static char *arr;
static char buffer[50];
char sn = 0;
char *str;
unsigned long n = num;

if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
n = -num;
sn = '-';
}
arr = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
str = &buffer[49];
*str = '\0';

do {
*__str = arr[n % be];
n /= be;
} while (n != 0);
{
if (sn)
*__str = sn;
return (str);
}
/**
* r_cmts - main
* @buf: address
*
* Return: Always 0.
*/
void r_cmts(char *buf)
{
int i;

for (i = 0; buf[i] != '\0'; i++)
if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
{
buf[i] = '\0';
break;
}
}
