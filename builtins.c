#include "shell.h"
/**
* _onehistory- main
*
* @inf: structure.
* Return: Always 0
*/
int _onehistory(inf_t *inf)
{
print_list(inf->history);
return (0);
}
/**
* unset_alias - main
* @inf: param struct
* @s: string.
* Return: Always 0.
*/
int unset_alias(inf_t *inf, char *s)
{
char *p, c;
int ren;

p = _strchr(str, '=');
if (!p)
return (1);

c = *p;
*p = 0;
ren = delete_node_at_index(&(info->alias),
get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
*p = c;
return (ren);
}
/**
* set_alias - main
* @inf: param struct.
* @s: string.
* Return: Always 0.
*/
int set_alias(inf_t *inf, char *s)
{
char *p;

p = _strchr(s, '=');
if (!p)
return (1);
if (!*++p)
return (unset_alias(inf, s));

unset_alias(inf, s);
return (add_node_end(&(inf->alias), s, 0) == NULL);
}
/**
* p_alias - main
* @node: alias.
*
* Return: Always 0.
*/
int p_alias(list_t *node)
{
char *p = NULL, *a = NULL;

if (node)
{
p = _strchr(node->s, '=');
for (a = node->s; a <= p; a++)
-putchar(*a);
_putchar('\'');
_puts(p + 1);
_puts("'\n");
return (0);
}
return (1);
}
/**
* _malias - main
* @inf: structure
* Return: Always 0.
*/
int _malias(inf_t *inf)
{
int i = 0;
char *p = NULL;
list_t *node = NULL;

if (inf->argc == 1)
{
node = inf->alias;
while (node)
{
p_alias(node);
node = node->next;
}
return (0);
}
for (i = 1; inf->argv[i]; i++)
{
p = strchr(inf->argv[i], '=');
if (p)
set_alias(inf, inf->argv[i]);
else
p_alias(node_starts_with(inf->alias, inf->atgv[i], '='));
}
return (0);
}

