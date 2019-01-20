/* PROGRAM: Computer Engineering Technology - Computing Science
AUTHOR:  Seongyeop Jeong, David Tang
DATE: March 2018
PURPOSE: A program that displays, adds, removes, and sorts properties using two separate linked lists
LEVEL OF DIFFICULTY: 5
CHALLENGES: Double pointers, pointers to functions, passing comparators, using brackets to specify pointer order of operation resolution
HOURS SPENT: 19 hours
*/


#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"


int main(void) {

	//INITIALIZE MAIN VARIABLES

	srand(time(NULL));
	Streets_t streets[] = {
        { "Cat street", 0 },
        { "Ferret Avenue", 0 },
        { "David Drive", 0 },
        { "Turtle Street", 0 },
        { "Tiger Avenue", 0 },
        { "Frog Drive", 0 },
        { "KingsWay Avenue", 0 },
        { "James Street", 0 },
        { "Impala Drive", 0 },
        { "WhynNot Street", 0 }
	};
	setStreetDistance(streets);
	Node *pHeadDefault = NULL;
	Node *pHeadFav = NULL;
	Node **ppHeadActive; // This double pointer keeps track of the active list by pointing to the head of that list
	ppHeadActive = &pHeadDefault;
	Node *pCurrentNode;
	int isDefault = 1;
	int iProperties = 0; // counter to keep track of index position in property list
	pComparator = &compareByRent;
	for (int i = 0; i < 6; i++)
		appendNode(ppHeadActive, createNewNode(&streets[rand() % 9]));
	//pCurrentNode = *ppHeadActive;
	sort(ppHeadActive, pComparator);
	//iProperties = 0;
	pCurrentNode = *ppHeadActive; // ALWAYS update current node after display, sorting, etc.

	//INITIAL DISPLAY
	
	printEntireList(pCurrentNode, isDefault);
	printf("\nWhat do you think about this rental property?\n");
	printSingleNode(pCurrentNode);

	//BEGIN INTERFACE

	char command[20];

	while (strcmp(command, "q") != 0) {

		printf("\nCommand ('h' for help): ");
		scanf("%s", command);

		if (strcmp(command, "h") == 0)
		{
			displayHelp();
		}
		else if (strcmp(command, "a") == 0)
		{
			sort(ppHeadActive, pComparator);
			iProperties = 0;
			pCurrentNode = *ppHeadActive; // ALWAYS update current node after display, sorting, etc.
			printEntireList(pCurrentNode, isDefault);
			if (getCount(*ppHeadActive) > 0) {
				printf("\nWhat do you think about this rental property?\n");
				printSingleNode(pCurrentNode);
			}
			else
				printf("\nThere are no more rental properties\n");

		}
		else if (strcmp(command, "f") == 0)
		{
			sort(ppHeadActive, pComparator);
			iProperties = 0;
			ppHeadActive = &pHeadFav;
			pCurrentNode = *ppHeadActive;
			isDefault = 0;
			printEntireList(pCurrentNode, isDefault);
			if (getCount(*ppHeadActive) > 0) {
				printf("\nWhat do you think about this rental property?\n");
				printSingleNode(pCurrentNode);
			}
			else
				printf("\nThere are no more rental properties\n");

		}
		else if (strcmp(command, "d") == 0)
		{
			sort(ppHeadActive, pComparator);
			iProperties = 0;
			ppHeadActive = &pHeadDefault;
			pCurrentNode = *ppHeadActive;
			if (rand() % 100 > 50) { // 50% chance of adding a new property
				appendNode(ppHeadActive, createNewNode(&streets[rand() % 9]));
				pCurrentNode = *ppHeadActive;
			}
			isDefault = 1;
			printEntireList(pCurrentNode, isDefault);
			if (getCount(*ppHeadActive) > 0) {
				printf("\nWhat do you think about this rental property?\n");
				printSingleNode(pCurrentNode);
			}
			else
				printf("\nThere are no more rental properties\n");

		}
		else if (strcmp(command, "l") == 0) // delete the current property
		{
			if (pCurrentNode != NULL) {
				if (pCurrentNode->pNext != NULL) {
					pCurrentNode = pCurrentNode->pNext;
					removeNodeAtIndex(ppHeadActive, iProperties);
					printf("\nWhat do you think about this rental property?\n");
					printSingleNode(pCurrentNode);
				}
				else {
					removeNodeAtIndex(ppHeadActive, iProperties);
					pCurrentNode = NULL;
					printf("\nThere are no more rental properties.");
				}
			}
			else
				printf("\nThere are no more rental properties.");

		}
		else if (strcmp(command, "r") == 0) // move current property to fav list
		{
			if (*ppHeadActive == pHeadFav) {

				if (pHeadFav == NULL)
					printf("The favorites list is empty");
                else if (pCurrentNode == NULL)
                    printf("There are no more properties in the favorites list.");
				else{
					printf("\nThis property is already on the favorites list.");
					printf("\n\nWhat do you think about this rental property?\n");
					printSingleNode(pCurrentNode);
				}
			}
			else {
				if (pCurrentNode != NULL) {
					if (pCurrentNode->pNext != NULL) {
						Node *pTemp = appendNodeAndReturn(&pHeadFav, createNewNode(&streets[rand() % 9])); // append a dummy to fav
						swap(pCurrentNode, pTemp);
						pCurrentNode = pCurrentNode->pNext;
						removeNodeAtIndex(ppHeadActive, iProperties);
						printf("\nWhat do you think about this rental property?\n");
						printSingleNode(pCurrentNode);
					}
					else {
						Node *pTemp = appendNodeAndReturn(&pHeadFav, createNewNode(&streets[rand() % 9])); // append a dummy to fav
						swap(pCurrentNode, pTemp);
						removeNodeAtIndex(ppHeadActive, iProperties);
						pCurrentNode = NULL;
						printf("\nThere are no more rental properties.");
					}
				}
				else
					printf("\nThere are no more rental properties.");
			}
		}
		else if (strcmp(command, "n") == 0)
		{

			if (pCurrentNode != NULL) {
				if (pCurrentNode->pNext != NULL) {
					iProperties++;
					pCurrentNode = pCurrentNode->pNext;
					printf("\nWhat do you think about this rental property?\n");
					printSingleNode(pCurrentNode);
				}
				else {
					printf("\nThere are no more rental properties after this one.\n");
					printf("\nWhat do you think about this rental property?\n");
					printSingleNode(pCurrentNode);
				}
			}
			else
				printf("There are no more rental properties.");
		}
		else if (strcmp(command, "sa") == 0)
		{
			pComparator = &compareByAddress;
			sort(ppHeadActive, pComparator);
			iProperties = 0;
			pCurrentNode = *ppHeadActive; // ALWAYS update current node after display, sorting, etc.
			printEntireList(pCurrentNode, isDefault);
			if (getCount(*ppHeadActive) > 0) {
				printf("\nWhat do you think about this rental property?\n");
				printSingleNode(pCurrentNode);
			}
			else
				printf("\nThere are no more rental properties\n");
		}
		else if (strcmp(command, "sn") == 0)
		{
			pComparator = &compareByRooms;
			sort(ppHeadActive, pComparator);
			iProperties = 0;
			pCurrentNode = *ppHeadActive; // ALWAYS update current node after display, sorting, etc.
			printEntireList(pCurrentNode, isDefault);
			if (getCount(*ppHeadActive) > 0) {
				printf("\nWhat do you think about this rental property?\n");
				printSingleNode(pCurrentNode);
			}
			else
				printf("\nThere are no more rental properties\n");

		}
		else if (strcmp(command, "sr") == 0)
		{
			pComparator = &compareByRent;
			sort(ppHeadActive, pComparator);
			iProperties = 0;
			pCurrentNode = *ppHeadActive; // ALWAYS update current node after display, sorting, etc.
			printEntireList(pCurrentNode, isDefault);
			if (getCount(*ppHeadActive) > 0) {
				printf("\nWhat do you think about this rental property?\n");
				printSingleNode(pCurrentNode);
			}
			else
				printf("\nThere are no more rental properties\n");
		}
		else if (strcmp(command, "sd") == 0)
		{
			pComparator = &compareByDistance;
			sort(ppHeadActive, pComparator);
			iProperties = 0;
			pCurrentNode = *ppHeadActive; // ALWAYS update current node after display, sorting, etc.
			printEntireList(pCurrentNode, isDefault);
			if (getCount(*ppHeadActive) > 0) {
				printf("\nWhat do you think about this rental property?\n");
				printSingleNode(pCurrentNode);
			}
			else
				printf("\nThere are no more rental properties\n");
		}
		else if (strcmp(command, "q") == 0)
		{
			printf("\nQuitting\n");

		}
		else {
			printf("\nThat is not a supported command\n");
			while (getchar()!='\n'); // Clear the buffer
			displayHelp();
		}
	}//endwhile

	return 0;
}

void displayHelp() {
	printf("Valid Commands are: \n");
	printf("\th\t - display this help\n");
	printf("\ta\t - display all the rental properties on the current list\n");
	printf("\tf\t - switch to the favourites list\n");
	printf("\td\t - switch to the default list\n");
	printf("\tl\t - 'swipe left' on the current rental property\n");
	printf("\tr\t - 'swipe right' on the current rental property\n");
	printf("\tn\t - skip to the next rental property\n");
	printf("\tsa\t - set the sorting to 'by address'\n");
	printf("\tsn\t - set the sorting to 'by number of rooms'\n");
	printf("\tsr\t - set the sorting to 'by rent'\n");
	printf("\tsd\t - set the sorting to 'by distance'\n");
	printf("\tq\t - quit the program\n");
}





