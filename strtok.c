#include <stdio.h>
#include <string.h>
int main()
{
	char text[] = "I am in love with you";
	char delim[] = " ";

	char *token = strtok(text, delim);
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, delim);
	}
	return (0);
}
