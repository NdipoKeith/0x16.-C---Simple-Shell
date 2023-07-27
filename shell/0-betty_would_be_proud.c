#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i, sum = 0, product = 1;
	char operation;

	printf("what do operation would you like to perform multiplication(*) or addition(+) ?\n");
	operation = getchar();

	if (argc > 1)
	{
		for (i = 1; i < argc; i++)
		{
			sum += atoi(argv[i]);
			product *= atoi(argv[i]);
		}

		if (operation == '+')
		{
			printf("Sum of numbers is: %d\n", sum);
		}
		else
		{
			printf("Product of numbers is: %d\n", product);
		}
	}
	return (0);
}
