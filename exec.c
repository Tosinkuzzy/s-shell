#include <stdio.h>
#include <unistd.h>

/**
* Main - Execve
*
* Return: Always 0.
*/
int main(void)
{
char *argv[] = {"/bin/ls", "-1", "/usr", NULL};
printf("Before Execve\n");
if (execve(argv[0], argv, NULL) == -1)
{
perror("Error");
}
printf("After execve\n");
return(0);
}
