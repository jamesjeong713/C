/* PROGRAM: Computer Engineering Technology - Computing Science
AUTHOR:  Seongyeop Jeong
DATE: Feb, 25, 2018
PURPOSE: to know how to use scanf with character classes.
LEVEL OF DIFFICULTY: 3.5
CHALLENGES: it was new to use the struct. and also I was confused the instruction what I have to make them exactly. (it might be English Problem)
HOURS SPENT: 19 hours
*/
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct properOfStreet_t
{
	int streetNumbers;
	char* streetName;
	int numBedrooms;
	int rentFee;
} ProperOfStreet;

void createStreets(ProperOfStreet streets[], int arraySize);
void sortedByProperties(ProperOfStreet* psussexStreet, int arraySize);
int compareByRooms(ProperOfStreet* pStreets, int count);
int compareByRent(ProperOfStreet* pStreets, int count);
int compareByName(ProperOfStreet* pStreets, int count);
void printStreet(ProperOfStreet* psussexStreet, int arraySize);

int main()
{
	srand(time(NULL));

	ProperOfStreet streets[] =
	{
		{ .streetNumbers = 24, "Sussex Drive" },
		{ .streetNumbers = 5, "Sussex Drive" },
		{ .streetNumbers = 1, "Sussex Drive" },
		{ .streetNumbers = 10, "Marvel Street" },
		{ .streetNumbers = 75, "Marvel Street" },
		{ .streetNumbers = 121, "Birds Street" },
		{ .streetNumbers = 15, "Nancy Drive\t" },
		{ .streetNumbers = 88, "Dragon Street" },
		{ .streetNumbers = 32, "Hello Street" },
		{ .streetNumbers = 58, "Kinght Drive" },
		{ .streetNumbers = 39, "Line Street\t" },
		{ .streetNumbers = 19, "Cacao Drive\t" },
	};
	int arraySize = sizeof(streets) / sizeof(streets[0]);

	createStreets(streets, arraySize);
	return 0;
}

void createStreets(ProperOfStreet streets[], int arraySize)
{
	int randRooms, randFee = 0;
	int numBedArray[] = { 1, 2, 3, 4 };
	int priceBedArray[] = { 400, 500, 600, 700, 800, 900, 1000, 1100, 1200 };

	for (int i = 0; i < arraySize; i++)
	{
		ProperOfStreet *sussexStreetPtr;
		sussexStreetPtr = &streets[i];
		
		randRooms = rand() % 4;
		randFee = rand() % 9;
		sussexStreetPtr->numBedrooms = numBedArray[randRooms];
		sussexStreetPtr->rentFee = priceBedArray[randFee];
	}
	sortedByProperties(streets, arraySize);
}

void sortedByProperties(ProperOfStreet* pStreets, int arraySize)
{
	ProperOfStreet tmp;

	for (int i = 0; i < arraySize; i++)
	{
		for (int j = 0; j < arraySize-1; j++)
		{
			if (compareByRooms(pStreets, j) > 0)
			{
				tmp = pStreets[j];
				pStreets[j] = pStreets[j + 1];
				pStreets[j + 1] = tmp;
			}
		}
	}
	printf("Sorted by Rooms\n");
	printf("Address\t\t\t\t# Rooms\t   Rent\n");
	printf("--------------------------\t-------\t-------\n");
	printStreet(pStreets, arraySize);

	for (int i = 0; i < arraySize; i++)
	{
		for (int j = 0; j < arraySize-1; j++)
		{
			if (compareByRent(pStreets, j) > 0)
			{
				tmp = pStreets[j];
				pStreets[j] = pStreets[j+1];
				pStreets[j+1] = tmp;
			}
		}
	}
	printf("Sorted by Rent\n");
	printf("Address\t\t\t\t# Rooms\t   Rent\n");
	printf("--------------------------\t-------\t-------\n");
	printStreet(pStreets, arraySize);

	for (int i = 0; i < arraySize; i++)
	{
		for (int j = 0; j < arraySize-1; j++)
		{
			if (compareByName(pStreets, j) > 0)
			{
				tmp = pStreets[j];
				pStreets[j] = pStreets[j + 1];
				pStreets[j + 1] = tmp;
			}
		}
	}
	printf("Sorted by address\n");
	printf("Address\t\t\t\t# Rooms\t   Rent\n");
	printf("--------------------------\t-------\t-------\n");
	printStreet(pStreets, arraySize);
}

int compareByRooms(ProperOfStreet* pStreets, int count)
{
	int diff = pStreets[count].numBedrooms - pStreets[count + 1].numBedrooms;
	if (diff == 0)
		diff = pStreets[count].rentFee - pStreets[count + 1].rentFee;
	return diff;
}

int compareByRent(ProperOfStreet* pStreets, int count)
{
	int diff = pStreets[count].rentFee - pStreets[count+1].rentFee;
	if (diff == 0)
		diff = pStreets[count].numBedrooms - pStreets[count+1].numBedrooms;
	return diff;
}

int compareByName(ProperOfStreet* pStreets, int count)
{
	int diff = strcmp(pStreets[count].streetName, pStreets[count+1].streetName);
	if (diff == 0)
		diff = pStreets[count].streetNumbers - pStreets[count + 1].streetNumbers;
	return diff;
}

void printStreet(ProperOfStreet* pStreets, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		printf("%3d %s\t\t %6d\t%7d\n", pStreets[i].streetNumbers, pStreets[i].streetName, pStreets[i].numBedrooms, pStreets[i].rentFee);
	}
	printf("\n");
}
