#include <stdio.h> //for printf
#include <stdlib.h> //for malloc




int main(void)
{
	//variable declarations
	int* ptr;
	int size;
	int temp;

	//code
	printf("Enter size of elements : ");
	scanf("%d", &size);
	
	ptr = (int*)malloc(size * sizeof(int));


	if (ptr == NULL)
	{
		printf("Memory not allocated.\n");
	}
	else
	{
		printf("Memory successfully allocated using malloc.\n\n");

		//insert the elements in an array
		for (int idx = 0; idx < size; idx++)
		{
			//ptr[idx] = idx + 1;
			printf("Enter value for element number %d : ", idx + 1);
			scanf("%d", &ptr[idx]);
		}

		printf("\n");

		//display the elements of an array
		printf("Entered elements of the array are: ");
		for (int idx = 0; idx < size; idx++)
		{
			printf("%d ", ptr[idx]);
		}

		printf("\n\n");		

		//reversing the array
		for (int idx = 0; idx < size / 2; idx++)
		{
			temp = ptr[idx];
			ptr[idx] = ptr[size - idx - 1];
			ptr[size - idx - 1] = temp;
		}

		printf("Reversed elements of the array are: ");
		for (int idx = 0; idx < size; idx++)
		{
			printf("%d ", ptr[idx]);
		}

		printf("\n\n");

	}

	return(0);
}
