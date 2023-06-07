#include <stdio.h> //for printf()


int main(void)
{
	//variable declarations
	int vsb_i, vsb_j, vsb_c;

	//code
	printf("\n\n");
	for (vsb_i = 0; vsb_i < 64; vsb_i++)
	{
		for (vsb_j = 0; vsb_j < 64; vsb_j++)
		{
			vsb_c = ((vsb_i & 0x8) == 0) ^ ((vsb_j & 0x8) == 0);

			if (vsb_c == 0)
				printf("__");

			if (vsb_c == 1)
				printf("* ");
				
		}
		printf("\n\n");
	}
	return(0);
}
