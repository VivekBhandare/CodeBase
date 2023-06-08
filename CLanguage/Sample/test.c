#include <stdio.h>

int main(void)
{
	char ch;
	printf("Enter ch : ");
	scanf("%c", &ch);

	switch (ch)
	{

	case 'A':
	case 'a':
		printf("Entered %c\n", ch);
		break;

	case 'B':
		printf("Entered %c\n", ch);
		break;

	default:
		printf("Something %c else entered\n", ch);
		break;

	}
}
