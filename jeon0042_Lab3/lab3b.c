/* PROGRAM: Computer Engineering Technology - Computing Science
AUTHOR:  Seongyeop Jeong
DATE: Feb, 10, 2018
PURPOSE: to know how to use scanf with character classes.
LEVEL OF DIFFICULTY: 5
CHALLENGES: comparing to last lab assignment, it is a bit difficult because the pointer is new feature for me.
HOURS SPENT: 18 hours
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shuffleDeck(char* deckArray[]);
void swapCards(char* deckarray[], int i, int r);
void getUserInput(int * playerNum);
void getSizeInput(int * handSizePerPlayer);
void getHopeInput(char* deckarray[], int playerNum, int handSize);

int main()
{
	srand(40885882);
	int handSize, playerNum;
	char* deck[52] = { "AH", "2H", "3H", "4H","5H","6H","7H","8H","9H","10H","JH","QH","KH",
		"AD", "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "10D", "JD", "QD", "KD",
		"AC", "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "10C", "JC", "QC", "KC",
		"AS", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "10S", "JS", "QS", "KS" };
	getUserInput(&playerNum);
	getSizeInput(&handSize);
	getHopeInput(deck, playerNum, handSize);

	return 0;
}

void shuffleDeck(char* deckArray[])
{
	int i = 0;
	int totalDeckSize = 52;
	int random = 0;
	for (i = 0; i < totalDeckSize; i++) {
		random = rand() % totalDeckSize;
		swapCards(deckArray, i, random);
	}
}


void swapCards(char* deckArray[], int i, int r)
{
	char* temp;
	temp = deckArray[i];
	deckArray[i] = deckArray[r];
	deckArray[r] = temp;
}

void getUserInput(int* playerNum)
{
	int userInput = 0;
	while (1)
	{
		printf("how many players?");
		scanf("%d", &userInput);
		if (userInput > 0 && userInput < 52)
		{
			*playerNum = userInput;
			break;
		}
		else {
			printf("Invalid input.. how many players?\n");
			while (getchar() != '\n');
		}
	}
}

void getSizeInput(int* handSizePerPlayer)
{
	int userInput = 0;
	while (1)
	{
		printf("How many cards per player? ");
		scanf("%d", &userInput);
		if (userInput > 0 && userInput < 52)
		{
			*handSizePerPlayer = userInput;
			break;
		}
		else {
			printf("Invalid input... How many cards per player?\n");
			while (getchar() != '\n');
		}
	}
}

void getHopeInput(char* deckArray[], int playerNum, int handSize)
{
	shuffleDeck(deckArray);
	int userInput = 0;
	while (1) {
		while (getchar() != '\n');
		printf("Who's hand do you want to see (or 0 to quit)? ");
		scanf("%d", &userInput);
		if (userInput > 0 && userInput <= playerNum) {
			printf("Player %d : [ ", userInput);
			int count = 0;
			for (int a = userInput-1; a < playerNum*handSize; a+=playerNum) {
				printf("%s", deckArray[a]);
				count++;
				if (count == handSize) {
					printf(" ]\n");
				}
				else {
					printf(", ");
				}
			}
		}
		else if (userInput == 0) {
			break;
		}
		else {
			printf("Invalid input... Who's hand do you want to see (or 0 to quit)?\n");
		}
	}
}
