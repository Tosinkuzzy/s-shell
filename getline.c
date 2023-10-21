#include "shell.h"

/**
 * ipt_buf - main
 * @inf: param struct
 * @buf: addressr
 * @len: address of len
 *
 * Return: Always 0.
 */
ssize_t ipt_buf(inf_t *inf, char **buf, size_t *len)
{
ssize_t i = 0;
size_t len_r = 0;

if (!*len)
{

free(*buf);
*buf = NULL;
signal(SIGINT, sigintHandler);
i = getline(buf, &len_r, stdin);
i = _getline(inf, buf, &len_r);
if (i > 0)
{
if ((*buf)[i - 1] == '\n')
{
(*buf)[i - 1] = '\0';
i--;
}
inf->linecount_flag = 1;
rem_comments(*buf);
build_history_list(inf, *buf, inf->histcount++);
{
*len = i;
inf->cmd_buf = buf;
}
}
}
return (i);
}

/**
 * get_ipt - main
 * @inf: param struct
 *
 * Return: Always 0.
 */
ssize_t get_ipt(inf_t *inf)
{
static char *buf;
static size_t i, j, len;
ssize_t r = 0;
char **buf_p = &(inf->arg), *p;

_putchar(BUF_FLUSH);
r = ipt_buf(info, &buf, &len);
if (r == -1)
return (-1);
if (len)
{
j = i;
p = buf + i;

check_chain(inf, buf, &j, i, len);
while (j < len)
{
if (is_chain(inf, buf, &j))
break;
j++;
}

i = j + 1;
if (i >= len)
{
i = len = 0;
inf->cmd_buf_type = CMD_NORM;
}

*buf_p = p;
return (_strlen(p));
}

*buf_p = buf;
return (r);
}

/**
 * rd_buf - main
 * @inf: param struct
 * @buf: buffer
 * @i: size
 *
 * Return: Always 0.
 */
ssize_t rd_buf(inf_t *inf, char *buf, size_t *i)
{
ssize_t r = 0;

if (*i)
return (0);
r = read(inf->readfd, buf, READ_BUF_SIZE);
if (r >= 0)
*i = r;
return (r);
}

/**
 * _getline - main
 * @inf: param struct
 * @ptr: address of pointer to buffer
 * @length: size.
 *
 * Return: Always 0.
 */
int _getline(inf_t *inf, char **ptr, size_t *length)
{
static char buf[READ_BUF_SIZE];
static size_t i, len;
size_t k;
ssize_t r = 0, s = 0;
char *p = NULL, *new_p = NULL, *c;

p = *ptr;
if (p && length)
s = *length;
if (i == len)
i = len = 0;

r = read_buf(inf, buf, &len);
if (r == -1 || (r == 0 && len == 0))
return (-1);

c = _strchr(buf + i, '\n');
k = c ? 1 + (unsigned int)(c - buf) : len;
new_p = _realloc(p, s, s ? s + k : k + 1);
if (!new_p)
return (p ? free(p), -1 : -1);

if (s)
_strncat(new_p, buf + i, k - i);
else
_strncpy(new_p, buf + i, k - i + 1);

s += k - i;
i = k;
p = new_p;

if (length)
*length = s;
*ptr = p;
return (s);
}

/**
 * sigintHandler - main
 * @sig_num: the signal number
 *
 * Return: 0
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
_puts("\n");
_puts("$ ");
_putchar(BUF_FLUSH);
}
