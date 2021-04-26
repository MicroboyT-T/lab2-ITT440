#include <stdlib.h>	/* needed to define exit() */
#include <unistd.h>	/* needed for fork() and getpid() */
#include <stdio.h>	/* needed for printf() */
#include <sys/wait.h>

void parentTask()
{
 printf("Job is done!!\n");
}

int main(int argc, char **argv) 
{
	int pid;	/* process ID */
	char child1[20];
	char child2[20];
	char child3[20];
	char child4[20];
	
	switch (pid = fork())
	{
		case 0:		/* a fork returns 0 to the child */
			printf("What your first  child's name?\n");
			scanf("%[^\n]%*c",child1);
			printf("What your second child's name?\n");
			scanf("%[^\n]%*c",child2);
			printf("What your third  child's name?\n");
			scanf("%[^\n]%*c",child3);
			printf("What your fourth child's name?\n");
			scanf("%[^\n]%*c",child4);

		for(int i = 0; i <= 3; i++)
			{
			if(i == 0)
				{
				printf("I am the first  child: %s\n", child1);
				i = i+1;
				}

				if(i == 1)
					{
					printf("I am the second child: %s\n", child2);
					i = i + 1;
					}
					if(i == 2)
						{
						printf("I am the third  child: %s\n", child3);
						i = i + 1;
						}
						if (i == 3)
							{
							printf("I am the fourth child: %s\n", child4);
							i = i + 1;
							}
							else
								{
								perror("fork");
								return(1);
								}
			}
			break;

		default:	/* a fork returns a pid to the parent */
			wait(NULL);
			printf("As a parent:" );
			parentTask();
			break;

		case -1:	/* something went wrong */
			perror("fork");
		exit(1);
	}
	exit(0);
}
