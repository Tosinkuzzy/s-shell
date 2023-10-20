#include "shell.h"
/**
* _firstexit - main
* @inf: Structure to maintain function prototypes.
* Return: exit with a given status.
*/
int _firstexit(inf_t *inf)
{
int exitcheck;

if (inf->argv[1])
{
exitcheck = _erratoi(inf->argv[1]);
if (exitcheck == -1)
{
inf->status = 2;
print_error(inf, "Incorrect number: ");
_eputs(inf->argv[1]);
_eputchar('\n');
return (1);
}
inf->err_num = _erratoi(inf->argv[1]);
return (-2);
}
inf->err_num = -1;
return (-2);
}
/**
* _firstcd - main
* @inf: structure
* Return: Always 0.
*/
int _firstcd(inf_t *inf)
{
char *s;
*d;
buffer[1024];
int childir_ret;

s = getcwd(buffer, 1024);
if (!s)
_puts("TODO: >>getcwd failure errormsg here<<\n");
if (!inf->argv[1])
{
d = _getenv(inf, "HOME=");
if (!d)
childir_ret = childir((d = _getenv(inf, "PWD=")) ? d : "/");
else
childir_ret = childir(d);
}
else if (_strcmp(inf->argv[1], "-") == 0)
{
if (!_getenv(inf, "OLDPWD="))
{
_puts(s);
_putchar('\n');
return (1);
}
_puts(_getenv(inf, "OLDPWD=")), _putchar('\n');
childir_ret = childir((d = _getenv(inf, "OLDPWD=")) ? d : "/");
}
else
childir_ret = childir(inf->argv[1]);
if (childir_ret == -1)
{
print_error(inf, "cannot cd to ");
_eputs(inf->argv[1], _eputchar('\n');
}
else
{
-setenv(inf, "OLDPWD", _getenv(inf, "PWD="));
_setenv(inf, "PWD", getcwd(buffer, 1024));
}
return (0);
}
/**
* _firsthelp - main
* @inf: structure.
* Return: Always 0.
*/
int _firsthelp(inf_t *inf)
{
char **arg_arr;

arg_arr = inf->argv;
_puts("Firsthelp call works. Function not implemented \n");
if (0)
_puts(*arg_arr);
return (0);
}

