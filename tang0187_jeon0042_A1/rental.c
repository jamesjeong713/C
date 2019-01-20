/* PROGRAM: Computer Engineering Technology - Computing Science
AUTHOR:  Seongyeop Jeong, David Tang
DATE: March 2018
PURPOSE: A program that displays, adds, removes, and sorts properties using two separate linked lists
LEVEL OF DIFFICULTY: 5
CHALLENGES: Double pointers, pointers to functions, passing comparators, using brackets to specify pointer order of operation resolution
HOURS SPENT: 19 hours
*/



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"


//Initialize
void setStreetDistance(Streets_t *pStreet_t)
{
	for (int i = 0; i < 10; i++)
	{
		pStreet_t[i].streetDistance = (float)((rand() % 35 + 5) * 100);
		//printf("\n%f", pProperty->propertyDistance);
	}
}

//Initialize
void initProperty(Property *pProperty, Streets_t *pStreet_t) {
	pProperty->pStreet = pStreet_t;
	pProperty->number = rand() % 200 + 1;
	pProperty->rooms = rand() % 4 + 1;
	pProperty->rent = (rand() % 8 + 4) * 50;
	pProperty->propertyDistance = (float)pStreet_t->streetDistance + (20 * pProperty->number);
}

//Print out just one node
void printSingleNode(Node *pHead) {
	if (pHead == NULL)
		printf("\nError, empty list.\n");
	else {
		printf("\tAddr: %d %s, # Rooms: %d, Rent/Room: $%d, Distance: %5.2f km\n", pHead->pProperty->number, pHead->pProperty->pStreet->streetName, pHead->pProperty->rooms, pHead->pProperty->rent, pHead->pProperty->propertyDistance/1000);
	}
}


//Print out the entire list
void printEntireList(Node *pHead, int isDefault) {
	if (isDefault){
        printf("\nUndecided Rental Properties\n");
	}
    else{
        printf("\nFavorite Rental Properties\n");
    }
	printf("Address\t\t\t\t # Rooms\t Rent/Room\t Distance\n");
	printf("---------------------------\t -------\t ---------\t ----------\n");

	if (pHead == NULL)
		printf("\nThis list is empty.\n");
	else {
		for (Node *pTempNode = pHead; pTempNode != NULL; pTempNode = pTempNode->pNext) {
			printf("%3d %-22s\t %7d\t %9d\t %7.2f km\n", pTempNode->pProperty->number, pTempNode->pProperty->pStreet->streetName, pTempNode->pProperty->rooms, pTempNode->pProperty->rent, pTempNode->pProperty->propertyDistance/1000);
		}
	}

}

