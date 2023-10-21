#include "shell.h"

/**
 * get_environ - main
 * @inf: Structure.
 * Return: Always 0
 */
char **get_environ(inf_t *inf)
{
if (!inf->environ || inf->env_changed)
{
inf->environ = list_to_strings(inf->env);
inf->env_changed = 0;
}

return (inf->environ);
}

/**
 * _unsetenv - main
 * @inf: Structure.
 *  Return: 1, 0 otherwise
 * @var: property
 */
int _unsetenv(inf_t *inf, char *var)
{
list_t *node = inf->env;
size_t i = 0;
char *p;

if (!node || !var)
return (0);

while (node)
{
p = starts_with(node->str, var);
if (p && *p == '=')
{
inf->env_changed = delete_node_at_index(&(inf->env), i);
i = 0;
node = inf->env;
continue;
}
node = node->next;
i++;
}
return (inf->env_changed);
}

/**
 * _setenv - main
 * @inf: Structure.
 * @var: string
 * @value: string  value
 * Return: Always 0
 */
int _setenv(inf_t *inf, char *var, char *value)
{
char *buf = NULL;
list_t *node;
char *p;

if (!var || !value)
return (0);

buf = malloc(_strlen(var) + _strlen(value) + 2);
if (!buf)
return (1);
_strcpy(buf, var);
_strcat(buf, "=");
_strcat(buf, value);
node = inf->env;
while (node)
{
p = starts_with(node->str, var);
if (p && *p == '=')
{
free(node->str);
node->str = buf;
inf->env_changed = 1;
return (0);
}
node = node->next;
}
add_node_end(&(inf->env), buf, 0);
free(buf);
inf->env_changed = 1;
return (0);
}
