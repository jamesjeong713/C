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


void swap(Node *pNodeA, Node *pNodeB) {

	Property *temp = pNodeA->pProperty;
	pNodeA->pProperty = pNodeB->pProperty;
	pNodeB->pProperty = temp;

}

int compareByRent(Property *A, Property *B) {

	return (A->rent - B->rent == 0 ? A->rooms - B->rooms : A->rent - B->rent);

}

int compareByRooms(Property *A, Property *B) {

	return (A->rooms - B->rooms == 0 ? A->rent - B->rent : A->rooms - B->rooms);

}

int compareByAddress(Property *A, Property *B) {

	int diff = strcmp(A->pStreet->streetName, B->pStreet->streetName);
	if (diff == 0)
		diff = A->number - B->number;
	return diff;
}

int compareByDistance(Property *A, Property *B) {
	return (int)(A->propertyDistance - B->propertyDistance);
}

void sort(Node **pHead, int(*pComparator)(Property *A, Property *B)) {

	for (int i = 0; i < getCount(*pHead) - 1; i++) {
		for (int j = 0; j < getCount(*pHead) - i - 1; j++)
		{
			Node *pA = getNodeAtIndex(*pHead, j);
			Node *pB = getNodeAtIndex(*pHead, j + 1);
			if ((*pComparator)(pA->pProperty, pB->pProperty) >= 0) {
				swap(pA, pB);
			}
		}
	}

}