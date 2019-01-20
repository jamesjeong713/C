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


void appendNode(Node **ppHead, Node *pNewNode) {
	if (*ppHead == NULL)
		*ppHead = pNewNode;
	else
	{
		Node *pNode = *ppHead;
		while (pNode->pNext != NULL)
			pNode = pNode->pNext;
		pNode->pNext = pNewNode;
	}
	pNewNode->pNext = NULL;
}

Node* appendNodeAndReturn(Node **ppHead, Node *pNewNode) {
	if (*ppHead == NULL) {
		*ppHead = pNewNode;

	}
	else
	{
		Node *pNode = *ppHead;
		while (pNode->pNext != NULL)
			pNode = pNode->pNext;
		pNode->pNext = pNewNode;
	}
	pNewNode->pNext = NULL;
	return pNewNode;
}

Node *createNewNode(Streets_t *pPropertyStreet)
{
	Node *pNode = calloc(1, sizeof(Node));
	Property *pProperty = calloc(1, sizeof(Property));

	initProperty(pProperty, pPropertyStreet);
	pNode->pProperty = pProperty;

	return pNode;
}


int getCount(Node *pHead) {

	int count = 0;

	if (pHead == NULL)
		return count;
	else {
		for (Node *pTempNode = pHead; pTempNode != NULL; pTempNode = pTempNode->pNext) {
			count++;
		}
	}
	return count; // count will be the number of nodes in the list (NOT INDEX)
}


Node *getNodeAtIndex(Node *pHead, int i) {

	Node *pTempNode = pHead;
	int j = 0;

	if (i + 1 > getCount(pHead))
		return NULL; // if the index of the requested node is bigger than the COUNT of nodes in total, fail

	if (pHead == NULL)
		return NULL;
	else {
		while (pTempNode != NULL) {
			if (j == i)
				return pTempNode;
			j++;
			pTempNode = pTempNode->pNext;
		}
	}
	return NULL; // if a NULL is returned it is a bad result
}


void insertNode(Node **ppHead, Node *pNewNode, int i) {

	Node *pTempNode = *ppHead;
	int j = 0;

	if (i + 1 > getCount(*ppHead))
		return; // if the index of the requested node is bigger than the COUNT of nodes in total, fail

	if (*ppHead == NULL)
		return;
	else {
		while (pTempNode != NULL) {

			if (i == 0) {
				pNewNode->pNext = *ppHead;
				*ppHead = pNewNode;
				return;
			}
			else if (j + 1 == i) {
				pNewNode->pNext = pTempNode->pNext;
				pTempNode->pNext = pNewNode;
				return;
			}
			j++;
			pTempNode = pTempNode->pNext;
		}//endwhile
	}

}


void removeNodeAtIndex(Node **ppHead, int i) {
	Node *pTempNode = *ppHead;
	Node *pDeletedNode = NULL;
	int j = 0;

	if (i + 1 > getCount(*ppHead))
		return; // if the index of the requested node is bigger than the COUNT of nodes in total, fail

	if (*ppHead == NULL)
		return;
	else {
		while (pTempNode != NULL) {

			if (i == 0) {
				if ((*ppHead)->pNext != NULL) {
					*ppHead = (*ppHead)->pNext; //Brackets are MANDATORY due to order of operations processessing!
					free(pTempNode);
					return;
				}
				else {
					*ppHead = NULL;
					free(pTempNode);
					return;
				}
			}
			else if (j + 1 == i) {
				if (pTempNode->pNext->pNext == NULL) {
					free(pTempNode->pNext);
					pTempNode->pNext = NULL;

					return;
				}
				else {
					pDeletedNode = pTempNode->pNext;
					pTempNode->pNext = pTempNode->pNext->pNext;
					free(pDeletedNode);

					return;
				}
			}
			j++;
			pTempNode = pTempNode->pNext;
		}//endwhile
	}
}