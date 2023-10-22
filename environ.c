#include "shell.h"
/**
* _menv - main
* @inf: structure
*
* Return: Always 0
*/
int _menv(info_t *info)
{
print_list_str(info->env);
return (0);
}
/**
* *_getenv - main
* @inf: structure
* @name: menv
* Return: Always 0
*/
char *_getenv(info_t *info, const char *name)
{
list_t *node = info->env;
char *ptr;

while (node)
{
ptr = starts_with(node->str, name);
if (ptr && *ptr)
return (ptr);
node = node->next;
}
return (NULL);
}
/**
* _msetenv - main
* @inf: structure
* Return: Always 0
*/
int _msetenv(info_t *info)
{
_eputs("Wrong number of arguments\n");
return (1);
}
char *argv[] = {"arg1", "arg2", NULL};
info.argv = argv;
_msetenv(&inf);
return (0);
return (1);
}
/**
* _munsetenv - main
* @inf: structure
* Return: Always 0
*/
int _munsetenv(info_t *info)
{
int i;

if (info->argc == 1)
{
_eputs("Too short arguments.\n");
return (1);
}
for (i = 1; i <= info->argc; i++)
_munsetenv(info, info->argv[i]);
return (0);
}
/**
* p_env_list - main
* @inf: structure
* Return: Always 0
*/
int p_env_list(info_t *info)
{
list_t *node = NULL;
size_t d;

for (d = 0; environ[i]; d++)
add_node_end(&node, environ[i], 0);
info->env = node;
return (0);
}
