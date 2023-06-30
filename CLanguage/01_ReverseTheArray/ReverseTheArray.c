#include <stdio.h> //for printf()
#include <stdlib.h> //for malloc()


int main(void)
{
	// Function declarations
	int print_array_elements(int*, int);

	// Variable declarations
	int* ptr = NULL;
	int size;
	int temp;

	// Code
	printf("Enter size of elements : ");
	scanf("%d", &size);
	
	// Dynamic or Run time memory allocation
	ptr = (int*)malloc(size * sizeof(int));


	if (ptr == NULL)
	{
		printf("Memory not allocated.\n");
	}

	else
	{
		printf("Memory successfully allocated using malloc().\n\n");

		// Insert the elements in an array
		for (int idx = 0; idx < size; idx++)
		{
			//ptr[idx] = idx + 1;
			printf("Enter value for element number %d : ", idx + 1);
			scanf("%d", &ptr[idx]);
		}

		printf("\n");

		// Display the elements of an array
		printf("Entered elements of the array are: ");
		print_array_elements(ptr, size);


		printf("\n\n");		

		// Reversing the array
		for (int idx = 0; idx < size / 2; idx++)
		{
			temp = ptr[idx];
			ptr[idx] = ptr[size - idx - 1];
			ptr[size - idx - 1] = temp;
		}

		printf("Reversed elements of the array are: ");
		print_array_elements(ptr, size);


		printf("\n\n");

	}

	// Freeing the memory, also wiping of the Base Address from ptr.
	if (ptr)
	{
		free(ptr);
		printf("Work done. Freed the memory allocated by malloc().");
		ptr = NULL;
	}

	return(0);
}


int print_array_elements(int* array_name, int array_size)
{
	// Code
	for (int idx = 0; idx < array_size; idx++)
	{
		printf("%d ", array_name[idx]);
	}

	return(0);
}
