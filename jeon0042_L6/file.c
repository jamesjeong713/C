/* PROGRAM: Computer Engineering Technology - Computing Science
AUTHOR:  Seongyeop Jeong
DATE: Apr, 2, 2018
PURPOSE: it is to know how to use file IO
LEVEL OF DIFFICULTY: 4
CHALLENGES: because of new feature, I was confused about it. 
there were lots of midterm and labs last week, even I was so sick on last weekend. Thus, I couldn't focus on making this lab assignment.. 
HOURS SPENT: 5 hours
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "types.h"
#include "rental.h"
#include "sort.h"
#include "file.h"

#define MAX_LINE_LENGH 512

bool readProperties(char *strFilename, RentalProperty **ppProperties)
{
	// YOU NOW NEED TO IMPLEMENT CODE TO OPEN THE SPECIFIED FILE, AND READ IN THE LIST, AS PER THE LAB REQUIREMENTS
	FILE *fileIn = fopen( strFilename, "r" );
	int numProperties = 0;
	if (fileIn != NULL)
	{
		char strLine[MAX_LINE_LENGH];
		char strArgument[MAX_LINE_LENGH];
		char strRemainder[MAX_LINE_LENGH];
		char comma;
		char bufferNumber[30];
		char bufferName[30];
		char bufferRent[30];
		char bufferRooms[30];
		int rc;
		int iLine = 1;
		// check variables if there is no.
		bool checkNumber = false;
		bool checkName = false;
		bool checkRent = false;
		bool checkRooms = false; 
		
		while(fgets(strLine, sizeof(strLine), fileIn))
		{
			do 
			{
				rc = sscanf( strLine, "%[^,]%[,] %[^\n]", strArgument, &comma, strRemainder);
				
				if ( strncmp( "streetNumber=", strArgument, 13 ) == 0 )
				{ 
					checkNumber = true;
					strcpy ( bufferNumber, strArgument + 13 );
				}
				else if ( strncmp( "streetName=", strArgument, 11 ) == 0 )
				{
					checkName = true;		
					strcpy ( bufferName, strArgument + 11 );					
				}			
				else if ( strncmp( "rent=", strArgument, 5 ) == 0 )
				{
					checkName = true;	
					strcpy ( bufferRent, strArgument + 5 );					
				}	
				else if ( strncmp( "rooms=", strArgument, 6 ) == 0 )
				{
					checkName = true;			
					strcpy ( bufferRooms, strArgument + 6 );					
				}	
				else 
				{			
					fprintf(stderr, "Invalid input at the line %d \n", iLine);
				}
				sscanf(strRemainder, "%[^\n]", strLine);
				//strcpy(strLine, strRemainder);
				/*else if (rc != EOF)
				{
					fprintf( stderr, "Invalid input on line %d\n", iLine);
				}
				else
				{
					break;
				}*/
				iLine++;

			} while (rc > 1);
			numProperties++;	
			*ppProperties = realloc(*ppProperties, sizeof(RentalProperty) * (numProperties + 1 ));
			for (int i = 0; i < numProperties; i++)
			{	
				(*ppProperties + i)->streetNumber = atoi(bufferNumber);
				(*ppProperties + i)->streetName = malloc(sizeof(bufferName));
				strcpy((*ppProperties + i)->streetName, bufferName);
				(*ppProperties + i)->rent = atoi(bufferRent);
				(*ppProperties + i)->rooms = atoi(bufferRooms);	
			}

		} // end loop

		if (!checkNumber || !checkName || !checkRent || !checkRooms)
		{
			fprintf(stderr, "In file, there is a missing set.\n");
		}

	} // end if statement
	else
	{
		fprintf(stderr, "The file '%s' could not be read\n", strFilename);
	}
			
	//Create null terminator properties and set to -1..
	*ppProperties = realloc( *ppProperties, sizeof(RentalProperty) * (numProperties + 1 ));
	(*ppProperties + numProperties)->streetName = NULL;
	(*ppProperties + numProperties)->streetNumber = -1;
	(*ppProperties + numProperties)->rent = -1;
	(*ppProperties + numProperties)->rooms = -1;
	fclose(fileIn);
	return true;		// everything was successfull
}

bool writeProperties(char *strFilename, RentalProperty *pProperties, SORT_METHOD eSortMethod, bool isReverse, int nNumResults, int nMin, int nMax, bool isAppend)
{
	sort(pProperties, eSortMethod);
	printList(pProperties, eSortMethod, isReverse, nNumResults, nMin, nMax);
	int numProperties = 0;
	FILE *fileOut;

	if (isAppend)
	{
		fileOut = fopen(strFilename, "a");
	}
	else if (!isAppend)
	{
		fileOut = fopen(strFilename, "w");
	}

	while (numProperties < countProperties(pProperties))
	{
		fprintf(fileOut, "streetName=%s ", (pProperties + numProperties)->streetName);
		fprintf(fileOut, "streetNumber=%d ", (pProperties + numProperties)->streetNumber);
		fprintf(fileOut, "rent=%d ", (pProperties + numProperties)->rent);
		fprintf(fileOut, "rooms=%d ", (pProperties + numProperties)->rooms);
		numProperties++;
	}

	free(pProperties);
	fclose(fileOut);
	// YOU NOW NEED TO IMPLEMENT CODE TO OPEN THE SPECIFIED FILE, AND WRITE OUT THE LIST, AS PER THE LAB REQUIREMENTS
	return true;		// everything was successfull
}
