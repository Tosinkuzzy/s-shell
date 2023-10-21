#include "shell.h"

/**
 * hist_file - main
 * @inf: parameter
 *
 * Return: Always 0.
 */

char *hist_file(inf_t *inf)
{
char *buf, *dir;

dir = _getenv(inf, "HOME=");
if (!dir)
return (NULL);
buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
if (!buf)
return (NULL);
buf[0] = 0;
_strcpy(buf, dir);
_strcat(buf, "/");
_strcat(buf, HIST_FILE);
return (buf);
}

/**
 * write_hist - main
 * @inf: param
 *
 * Return: 1, else -1
 */
int write_hist(inf_t *inf)
{
ssize_t fd;
char *filename = hist_file(inf);
list_t *node = NULL;

if (!filename)
return (-1);

fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
free(filename);
if (fd == -1)
return (-1);
for (node = inf->hist; node; node = node->next)
{
_putsfd(node->str, fd);
_putfd('\n', fd);
}
_putfd(BUF_FLUSH, fd);
close(fd);
return (1);
}

/**
 * read_hist - main
 * @inf: param
 *
 * Return: Always 0.
 */
int read_hist(inf_t *inf)
{
int i, last = 0, linecount = 0;
ssize_t fd, rdlen, fsize = 0;
struct stat st;
char *buf = NULL, *filename = hist_file(inf);

if (!filename)
return (0);

fd = open(filename, O_RDONLY);
free(filename);
if (fd == -1)
return (0);
if (!fstat(fd, &st))
fsize = st.st_size;
if (fsize < 2)
return (0);
buf = malloc(sizeof(char) * (fsize + 1));
if (!buf)
return (0);
rdlen = read(fd, buf, fsize);
buf[fsize] = 0;
if (rdlen <= 0)
return (free(buf), 0);
close(fd);
for (i = 0; i < fsize; i++)
if (buf[i] == '\n')
{
buf[i] = 0;
build_hist_list(inf, buf + last, linecount++);
last = i + 1;
}
if (last != i)
build_hist_list(inf, buf + last, linecount++);
free(buf);
inf->histcount = linecount;
while (inf->histcount-- >= HIST_MAX)
delete_node_at_index(&(inf->hist), 0);
renumber_hist(inf);
return (inf->histcount);
}
/**
 * build_hist_list - main
 * @inf: Structure
 * @buf: buffer
 * @linecount: the history linecount, histcount
 *
 * Return: Always 0
 */
int build_hist_list(inf_t *inf, char *buf, int linecount)
{
list_t *node = NULL;

if (inf->hist)
node = inf->hist;
add_node_end(&node, buf, linecount);

if (!inf->hist)
inf->hist = node;
return (0);
}

/**
 * renumber_hist - main
 * @inf: Structure.
 *
 * Return: Always 0.
 */
int renumber_hist(inf_t *inf)
{
list_t *node = inf->hist;
int i = 0;

while (node)
{
node->num = i++;
node = node->next;
}
return (inf->histcount = i);
}
