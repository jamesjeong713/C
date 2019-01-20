/********************************************************************************************************************
PROGRAM: Assignment2 - CST8234_013
AUTHOR: Kevin Lai, Seongyeop Jeong
DATE: April 18, 2018
PURPOSE: Learn IPC - Communicating two processes using pipes. Creating two arrays to  set up two pipes and forking
		 to create 2 processes than closing the proper ends of our pipes to create bi-directional commmunications.
LEVEL OF DIFFICULTY: 4/5
CHALLENGES: Getting signals to work between Child and Parent process
HOURS SPENT: 8
*********************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define READ 0
#define WRITE 1
extern void runAsParent(int fdRead, int fdWrite);
extern void runAsChild(int fdRead, int fdWrite);

int main()
{
	/*Create 2 arrays for pipes to create Bi-Directional Communication*/
	int pipeFDs_P2C[2];
	int pipeFDs_C2P[2];
	int fdRead;  /*hold file descriptor for our read end of the pipe*/
	int fdWrite;  /*hold file descriptor for our write end of the pipe*/

	/*create pipe and handle error if pipe cannot be created*/
	if (pipe(pipeFDs_P2C) < 0)
	{
		fprintf(stderr, "unable to create pipe");
		exit(EXIT_FAILURE);
	}

	if (pipe(pipeFDs_C2P) < 0)
	{
		fprintf(stderr, "unable to create pipe");
		exit(EXIT_FAILURE);
	}

	int pid = fork();  /*fork so we have 2 processes now (Parent & Child)*/

	if (pid != 0)
	{
		/*close the proper ends of our parent pipes*/
		close(pipeFDs_P2C[READ]);
		close(pipeFDs_C2P[WRITE]);

		/*set our file descriptors for parent*/
		fdWrite = pipeFDs_P2C[WRITE];
		fdRead = pipeFDs_C2P[READ];

		/*call runAsParent function for our parent process*/
		runAsParent(fdRead, fdWrite);

		/*close our file descriptors for parent process before ending our program*/
		close(fdRead);
		close(fdWrite);
	}
	else
	{
		/*close the proper ends of our child pipes*/
		close(pipeFDs_P2C[WRITE]);
		close(pipeFDs_C2P[READ]);

		/*set our file descriptors for child*/
		fdWrite = pipeFDs_C2P[WRITE];
		fdRead = pipeFDs_P2C[READ];

		/*call runAsChild function for our child process*/
		runAsChild(fdRead, fdWrite);

		/*close file descriptors for child process before ending program*/
		close(fdRead);
		close(fdWrite);
	}

	return 0;
}
