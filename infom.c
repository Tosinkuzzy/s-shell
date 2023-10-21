#include "shell.h"

/**
 * infom - main
 * @inf: address
 */
void infom(inf_t *inf)
{
inf->arg = NULL;
inf->argv = NULL;
inf->path = NULL;
inf->argc = 0;
}

/**
 * s_infom - main
 * @inf: address
 * @av: argument
 */
void s_infom(inf_t *inf, char **av)
{
int i = 0;

inf->fname = av[0];
if (inf->arg)
{
inf->argv = strtow(inf->arg, " \t");
if (!inf->argv)
{

inf->argv = malloc(sizeof(char *) * 2);
if (inf->argv)
{
inf->argv[0] = _strdup(inf->arg);
inf->argv[1] = NULL;
}
}
for (i = 0; inf->argv && inf->argv[i]; i++)
;
inf->argc = i;

replace_alias(inf);
replace_vars(inf);
}
}

/**
 * fr_infom - main
 * @inf:  address
 * @all: true if freeing
 */
void fr_infom(inf_t *inf, int all)

{
ffr(inf->argv);
inf->argv = NULL;
inf->path = NULL;
if (all)
{
if (!inf->cmd_buf)
free(inf->arg);
if (inf->env)
free_list(&(inf->env));
if (inf->history)
free_list(&(inf->history));
if (inf->alias)
free_list(&(inf->alias));
ffr(inf->environ);
inf->environ = NULL;
bfr((void **)inf->cmd_buf);
if (inf->readfd > 2)
close(inf->readfd);
_putchar(BUF_FLUSH);
}
}
