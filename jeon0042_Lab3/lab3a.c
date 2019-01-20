/* PROGRAM: Computer Engineering Technology - Computing Science
   AUTHOR:  Seongyeop Jeong
   DATE: Feb, 10, 2018
   PURPOSE: to know how to use scanf with character classes.
   LEVEL OF DIFFICULTY: 1
   CHALLENGES: 	
   HOURS SPENT: 1 Hour
*/

#include <stdio.h>
#include <string.h>

int main( void )
{
    char courseName[16];
    char courseID[8];
    char courseDescription[512];

    // initialize the course details
    strcpy( courseName, "C Programming" );
    strcpy( courseID, "CST0000" );
    strcpy( courseDescription, "An introduction to procedural languages" );

    // print out the details, and a prompt for the user to replace courseID
    printf( "\n\nOriginal Course Details\n=== %s - %s ===\n%s\n", courseID, courseName, courseDescription );

    for ( int i = 0; i < 3; i++ )
    {
	printf( "\nEnter a new course code (e.g., 'CST1234') for this course: " );

	/*******************************************
	 * HOW ARE YOU GOING TO SCAN THE INPUT?
	 *
	 * PLACE YOUR CODE BELOW THIS LINE
	 *******************************************/
	scanf( "%7[^\n]%*[^\n]", courseID );			

	// skip over the newline at the end of the input
	scanf( "%*c" );

	// report the new version
	printf( "Updated Course Details\n=== %s - %s ===\n%s\n", courseID, courseName, courseDescription );
    }
}

