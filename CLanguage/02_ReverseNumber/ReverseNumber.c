#include <stdio.h> // for printf() & scanf()
#include <math.h>  // for pow()


int main(void)
{
	// function declaration
	int give_number_of_digits(int);
	int reverse_number(int, int);

	// variable declarations
	int iNumber;
	int digit_count = 0;
	int iReverseNumber = 0;

	// code
	printf("Enter A Number Which You Want To Reverse : ");
	scanf("%d", &iNumber);

	// Storing number of digits in given number.
	digit_count = give_number_of_digits(iNumber);

	iReverseNumber = reverse_number(iNumber, digit_count);

	printf("\nEntered Number  = %d\n", iNumber);
	printf("Reversed Number = %d\n", iReverseNumber);

	return(0);
}


int give_number_of_digits(int num)
{
	// variable declarations
	int quotient;
	int num_of_digits = 0;


	// code
	do
	{
		quotient = num / 10;
		num = quotient;
		num_of_digits++;

	} while (quotient != 0);

	return(num_of_digits);
}


int reverse_number(int iNum, int dig_count)
{
	// variable declarations
	int quotient;
	int remainder;
	int iRevNum = 0;


	// code
	do
	{
		dig_count--;
		quotient = iNum / 10;
		remainder = iNum % 10;
		iRevNum = iRevNum + remainder * pow(10, dig_count);
		iNum = quotient;

	} while (quotient != 0);

	return(iRevNum);
}
