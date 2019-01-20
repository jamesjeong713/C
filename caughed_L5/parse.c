/* PROGRAM: Computer Engineering Technology - Computing Science
AUTHOR:  Seongyeop Jeong
DATE: Mar, 26, 2018
PURPOSE: it is to know how to use command line argument
LEVEL OF DIFFICULTY: 2
CHALLENGES: it is big challeng for me to translate instructions.. so it took a long time. and also i struggled to handle it with two kinds of test.
HOURS SPENT: 8 hours
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "types.h"
#include "rental.h"
#include "sort.h"

void printHelpAndExit(char *strCommand, int exitCode);
bool parseArguments(int argc, char *argv[], bool *pbReverse, SORT_METHOD *peSortMethod, int *pnNumResults, int *pnMin, int *pnMax);
int getUserInput(char* strCommand, char* argv);
/************************************************
* Note, this function always exits the program!
************************************************/
void printHelpAndExit(char *strCommand, int exitCode)
{
	if (exitCode == EXIT_SUCCESS)
		printf("\n%s - print some rental properties with user-selectable formatting options.\n", strCommand);

	printf("\nUsage: %s [arguments]\n\n", strCommand);
	printf("Arguments(in order):\n\n");
	printf("    -r, --reverse\t\tPrint the results in reverse order\n");
	printf("    -n <NUM>, --num=<NUM>\tOnly show values that are greater than or equal to the NUM\n");
	printf("    -m <NUM>, --min=<NUM>\tOnly show values that are greater than or equal to the NUM\n");
	printf("    -M <NUM>, --max=<NUM>\tOnly show values that are greater than or equal to the NUM\n");
	printf("    -s <SORT>, --sort=<SORT>\tMandatory: Use one of the following SORT methods:\n");
	printf("\t\t\t\t\t-s 0: byRooms - sort by the number of rooms\n");
	printf("\t\t\t\t\t-s 1: byAddress - sort by address\n");
	printf("\t\t\t\t\t-s 2: byRent - sort by rent\n");
	printf("    -h, --help\t\t\tPrint this message\n");

	exit(exitCode);
}

bool parseArguments(int argc, char *argv[], bool *pbReverse, SORT_METHOD *peSortMethod, int *pnNumResults, int *pnMin, int *pnMax)
{
	bool isPosixDefault = false;
	bool isNumResults = true;
	bool isMinimum = false;
	bool isMaximum = false;
	bool isSort = false;
	bool isReverse = false;
	// deafult values
	*pbReverse = false;
	*pnMax = INT_MAX;

	char* strPattern;
	// does the program name start with a local path specifier?
	char* strCommand = argv[0];
	if (strncmp("./", strCommand, 2) == 0)
	{
		strCommand += 2;
	}

	// replace the following code with your implementation
	if (argc == 1)
	{
		printf("\n%s: you must provide some arguments.\n", strCommand);
		printHelpAndExit(strCommand, EXIT_FAILURE);
	}
	else
	{
		for (int iArg = 1; iArg < argc; ++iArg)
		{
			if (strcmp("-h", argv[iArg]) == 0 || strcmp("--help", argv[iArg]) == 0)
			{
				printHelpAndExit(argv[iArg], EXIT_SUCCESS);
			}
			else if (strcmp("-r", argv[iArg]) == 0 || strcmp("--reverse", argv[iArg]) == 0)
			{
				isReverse = true;
				*pbReverse = true;
			}

			else if (strcmp("-n", argv[iArg]) == 0 || strcmp("--num", argv[iArg]) == 0)
			{
				strPattern = "--num=";
				isNumResults = true;

				if (strcmp("-n", argv[iArg]) == 0)
					isPosixDefault = true;

				if (isPosixDefault)
				{
					*pnNumResults = getUserInput(argv[iArg+1], argv[iArg]);
				}
				if (!isPosixDefault)
				{
					if (strlen(argv[iArg]) > strlen(strPattern))
						*pnNumResults = getUserInput(argv[iArg] + strlen(strPattern), argv[iArg]);
				}
					
			}

			else if (strcmp("-m", argv[iArg]) == 0 || strncmp("--min=", argv[iArg], 6) == 0)
			{
				strPattern = "--min=";
				isMinimum = true;

				if (strcmp("-m", argv[iArg]) == 0)
					isPosixDefault = true;

				if (isPosixDefault)
				{
					if (strlen(argv[iArg]) == 2)
						*pnMin = 0;

					*pnMin = getUserInput(argv[iArg+1], argv[iArg]);
				}
				if (!isPosixDefault)
				{
					if (strlen(argv[iArg]) == strlen(strPattern)) // if minimum not provided,
						*pnMin = 0;
					else if (strlen(argv[iArg]) > strlen(strPattern))
						*pnMin = getUserInput(argv[iArg] + strlen(strPattern), argv[iArg]);
				}
				if (isPosixDefault)
					iArg++;
				isPosixDefault = false;
			}

			else if (strcmp("-M", argv[iArg]) == 0 || strncmp("--max=", argv[iArg], 6) == 0)
			{
				strPattern = "--max=";
				isMaximum = true;

				if (strcmp("-M", argv[iArg]) == 0)
					isPosixDefault = true;

				if (isPosixDefault)
					*pnMax = getUserInput(argv[iArg+1], argv[iArg]);

				if (!isPosixDefault)
				{
					if (strlen(argv[iArg]) > strlen(strPattern))
						*pnMax = getUserInput(argv[iArg] + strlen(strPattern), argv[iArg]);
				}
				if (isPosixDefault)
					iArg++;
				isPosixDefault = false;
			}

			else if (strcmp("-s", argv[iArg]) == 0 || strncmp("--sort=", argv[iArg], 7) == 0)
			{
				strPattern = "--sort=";
				isSort = true;

				if (strcmp("-s", argv[iArg]) == 0)
				{
					isPosixDefault = true;
				}

				if (isPosixDefault)
				{
					*peSortMethod = getUserInput(argv[++iArg], argv[iArg]);
				}

				if (!isPosixDefault)
				{
					if (strlen(argv[iArg]) > strlen(strPattern))
						*peSortMethod = getUserInput(argv[iArg] + strlen(strPattern), argv[iArg]);
				}

				// exceptions
				if (*peSortMethod < 0 || *peSortMethod > 2)
				{
					printf("Valid input should be given: 0-2 (sort by rent, rooms, address in order)");
					printHelpAndExit(argv[iArg], EXIT_FAILURE);
				}
				if (strlen(argv[iArg]) == 2)
				{
					printf("Valid input should be given: 0-2 (sort by rent, rooms, address in order)");
					printHelpAndExit(argv[iArg], EXIT_FAILURE);
				}
				if (isPosixDefault)
					iArg++;
				isPosixDefault = false;
			}
			else if (!isMaximum && !isMinimum && !isNumResults && !isSort && !isReverse)
			{
				printf("Please valid input");
				printHelpAndExit(argv[iArg], EXIT_FAILURE);
			}
		}
	}
	return true;
}

int getUserInput(char* strCommand, char* argv)
{
	char junk;
	int nInput = -1;
	int rc = sscanf(strCommand, "%d %c", &nInput, &junk);

	if (rc != 1)
	{
		printf("illegal number of results %s\n", strCommand);
		printHelpAndExit(argv, EXIT_FAILURE);
	}
	else
	{
		return nInput;
	}
	return -1;
}