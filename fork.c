#include <stdio.h>
#include <unistd.h>

/**
* main - fork
* my_pid: getpid
*
* Return: Always 0.
*/
int main(void)
{
pid_t my_pid;
pid_t pid;

/* printf("Before fork\n"); */
pid = fork();
if (pid == -1)
{
perror("Error:");
return (1);
}
/*  printf("After fork\n"); */
my_pid = getpid();
if (my_pid == -1)
{
/* printf("My pid is %u\n", my_pid); */
return (0);
}
}
