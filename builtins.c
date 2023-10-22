#include "shell.h"
/**
* _onehistory- main
*
* @inf: structure.
* Return: Always 0
*/
int _onehistory(info_t *info)
{
print_list(info->history);
return (0);
}
/**
* unset_alias - main
* @inf: param struct
* @s: string.
* Return: Always 0.
*/
int unset_alias(info_t *info, char *s)
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
int set_alias(info_t *info, char *s)
{
char *p;

p = _strchr(s, '=');
if (!p)
return (1);
if (!*++p)
return (unset_alias(info, s));

unset_alias(info, s);
return (add_node_end(&(info->alias), s, 0) == NULL);
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
int _malias(info_t *info)
{
int i = 0;
char *p = NULL;
list_t *node = NULL;

if (info->argc == 1)
{
node = info->alias;
while (node)
{
p_alias(node);
node = node->next;
}
return (0);
}
for (i = 1; info->argv[i]; i++)
{
p = strchr(info->argv[i], '=');
if (p)
set_alias(info, info->argv[i]);
else
p_alias(node_starts_with(info->alias, info->atgv[i], '='));
}
return (0);
}

