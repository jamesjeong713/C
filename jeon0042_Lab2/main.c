#include <stdio.h> 
#include <stdlib.h>
 
int main(void)
{
	// initialize lineNumber which is one, and error which is 0.
	// default value of error is 0, this is to check if three values are -1 
    int lineNumber = 1, error = 0;
	// separate lines if it is just for default or checking.
    int probID = -1, qty = -1;
	// separate price with above int variables because of different primitive types
    float price = -1, total = 0.0f, amount = 0.0f;
	
	// output to prompt user input.
    printf("Enter multiple triplets of <product-id> <quantity> <price> (e.g., %d %d %.2f): \n", 362, 1, 19.95);

	// when scanf is not end of file, while loop is true.
    while (scanf("%d %d %f", &probID, &qty, &price) != EOF)
    {
		// if user do not input variable of three variables
		// one to two of them will be default value which is -1.
		// error variable is 1. while loop will break.
		// then go to error ternary section. 
        if (probID == -1 ||qty == -1 || price == -1) {
            error = 1;
            break;
        }
		
		// to make this frame at first time. (when the default value is 1)
        if (lineNumber == 1)
        {
			printf("Line\t Prod ID\t Qty\t Price\t\t Amount\n");
			printf("----\t -------\t ---\t -----\t\t ------\n");
        }
        amount = qty * price;
		
        printf("%4d\t %05d %13d %9.2f ", lineNumber, probID, qty, price);
        printf("%16.2f\n", amount);
        lineNumber++;
		
        total = total + amount;
		
		// when the first loop finish, 
		// those three variables have to be default value 1
		// to check errors if the user doesn't input variable.
        probID = qty = price = -1;
    }
	
	// ternary operator: if error is 1, print error message.
	// if error is 0, print out total message. 
    error ? printf("Error processing order 2\n") : printf("\t\t\t\t -----\t\t ------\n\t\t\t\t Total\t\t%7.2f\n", total);

    return 0;
}
