//Brian Leung made this
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/*
The child will multiply the number by 3
*/

int main()
{
	int fdp[2];
	int fdc[2];
	pipe(fdp);
	pipe(fdc);
	if (fork() == 0)
	{
		close(fdc[1]);
		close(fdp[0]);
		int recv;
		read(fdc[0],&recv,sizeof(recv));
		printf("Child: Received [%d]\n", recv);
		recv = recv*3;
		printf("Child: The number is now: [%d]\n", recv);
		printf("Child: Sending [%d] back\n", recv);
		write(fdp[1],&recv,sizeof(recv));

	}
	else
	{
		close(fdc[0]);
		close(fdp[1]);
		int send = 9;
		printf("Parent: Sending [%d]\n", send);
		write(fdc[1],&send,sizeof(send));
		read(fdp[0],&send,sizeof(send));
		printf("Parent: [%d] received from child\n", send);
		printf("Finished\n");
	}
	return 0;
}