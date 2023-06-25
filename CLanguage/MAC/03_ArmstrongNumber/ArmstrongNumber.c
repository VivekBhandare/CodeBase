#include <stdio.h> // for printf() & scanf()
#include <math.h>  // for pow()


int main(void)
{
	// function declarations
	void CheckForArmstrongNumber(int);

	// variable declarations
	int iNumber;

	// code
	printf("\nEnter A Integer Number : ");
	scanf("%d", &iNumber);
	
	CheckForArmstrongNumber(iNumber);

	return(0);
}


void CheckForArmstrongNumber(int num)
{
	// function declarations
	int give_number_of_digits(int);

	// variable declarations
	int num_original;
	int digit_count = 0;
	int quotient;
	int remainder;
	int tbd_armstrong_num = 0;
	
	// code
	printf("\nChecking Whether The Number %d Is An Armstrong Number Or Not ...\n", num);

	digit_count = give_number_of_digits(num);
	
	num_original = num;
	do
	{
		quotient = num / 10;
		remainder = num % 10;
		tbd_armstrong_num = tbd_armstrong_num + pow(remainder, digit_count);
		num = quotient;

	} while (quotient != 0);

	if (num_original == tbd_armstrong_num)
		printf("\nNumber %d Is An Armstrong Number.\n", num_original);
	else
		printf("\nNumber %d Is Not An Armstrong Number.\n", num_original);
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
