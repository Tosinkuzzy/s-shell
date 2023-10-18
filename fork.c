#include <stdio.h>
#include <unistd.h>

/**
* main - fork
* my_pid: getpid
* Child_pid: child process.
*
* Return: Always 0.
*/
int main(void)
{
pid_t my_pid;
pid_t Child_pid;

/* printf("Before fork\n"); */
Child_pid = fork();
if (Child_pid == -1)
{
perror("Error:");
return (1);
}
/*  printf("After fork\n"); */
my_pid = getpid();
/* printf("My pid is %u\n", my_pid); */
if (my_pid == 0)
{
/* printf("My pid is %u\n", my_pid); */
if (Child_pid == 0)
{
/* printf("(%u, I am your father\n", my_pid, Child_pid); */
}
return (0);
}
}
