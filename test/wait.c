#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
* main - fork & wait
*
* Return: Always 0.
*/
int main(void)
{
pid_t Child_pid;
int status;

Child_pid = fork();
if (Child_pid == -1)
{
perror("Error");
return (1);
}
if (Child_pid == 0)
{
print_string("wait for me, wait for me\n");
sleep(3);
}
else
{
wait(&status);
print_string("oh, it's al better now\n");
}
return (0);
}
