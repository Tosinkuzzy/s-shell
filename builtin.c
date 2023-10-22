#include "shell.h"
/**
* _firstexit - main
* @inf: Structure to maintain function prototypes.
* Return: exit with a given status.
*/
int _firstexit(info_t *info)
{
int exitcheck;

if (info->argv[1])
{
exitcheck = _erratoi(info->argv[1]);
if (exitcheck == -1)
{
info->status = 2;
print_error(info, "Incorrect number: ");
_eputs(info->argv[1]);
_eputchar('\n');
return (1);
}
info->err_num = _erratoi(info->argv[1]);
return (-2);
}
info->err_num = -1;
return (-2);
}
/**
* _firstcd - main
* @inf: structure
* Return: Always 0.
*/
int _firstcd(info_t *inf)
{
char *s;
*d;
buffer[1024];
int childir_ret;

s = getcwd(buffer, 1024);
if (!s)
_puts("TODO: >>getcwd failure errormsg here<<\n");
if (!info->argv[1])
{
d = _getenv(info, "HOME=");
if (!d)
childir_ret = childir((d = _getenv(info, "PWD=")) ? d : "/");
else
childir_ret = childir(d);
}
else if (_strcmp(info->argv[1], "-") == 0)
{
if (!_getenv(info, "OLDPWD="))
{
_puts(s);
_putchar('\n');
return (1);
}
_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
childir_ret = childir((d = _getenv(info, "OLDPWD=")) ? d : "/");
}
else
childir_ret = childir(info->argv[1]);
if (childir_ret == -1)
{
print_error(info, "cannot cd to ");
_eputs(info->argv[1], _eputchar('\n');
}
else
{
-setenv(info, "OLDPWD", _getenv(info, "PWD="));
_setenv(info, "PWD", getcwd(buffer, 1024));
}
return (0);
}
/**
* _firsthelp - main
* @inf: structure.
* Return: Always 0.
*/
int _firsthelp(info_t *info)
{
char **arg_arr;

arg_arr = info->argv;
_puts("Firsthelp call works. Function not implemented \n");
if (0)
_puts(*arg_arr);
return (0);
}

