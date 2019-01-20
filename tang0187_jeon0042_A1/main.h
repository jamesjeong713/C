/* PROGRAM: Computer Engineering Technology - Computing Science
AUTHOR:  Seongyeop Jeong, David Tang
DATE: March 2018
PURPOSE: A program that displays, adds, removes, and sorts properties using two separate linked lists
LEVEL OF DIFFICULTY: 5
CHALLENGES: Double pointers, pointers to functions, passing comparators, using brackets to specify pointer order of operation resolution
HOURS SPENT: 19 hours
*/


typedef struct Streets {
	char* streetName;
	float streetDistance;
} Streets_t;

typedef struct Property {
	int number;
	int rent;
	int	rooms;
	float propertyDistance;
	struct Streets *pStreet;
} Property;

typedef struct node {
	struct Property *pProperty;
	struct node *pNext;
} Node;

void setStreetDistance(Streets_t *pStreets);
void initProperty(Property *pProperty, Streets_t *pMyStreet);
Node *createNewNode(Streets_t *pPropertyStreet);
void appendNode(Node **ppHead, Node *pNewNode);
void printSingleNode(Node *pHead);
void printEntireList(Node *pHead, int isDefault);
int getCount(Node *pHead);
Node *getNodeAtIndex(Node *pHead, int i);
void insertNode(Node **ppHead, Node *pNewNode, int i);
void removeNodeAtIndex(Node **ppHead, int i);
void displayHelp();
void swap(Node *pNodeA, Node *pNodeB);
Node* appendNodeAndReturn(Node **ppHead, Node *pNewNode);
int(*pComparator)(Property *a, Property *b);
int compareByRent(Property *A, Property *B);
int compareByRooms(Property *A, Property *B);
int compareByAddress(Property *A, Property *B);
int compareByDistance(Property *A, Property *B);
void sort(Node **pHead, int(*pComparator)(Property *A, Property *B));