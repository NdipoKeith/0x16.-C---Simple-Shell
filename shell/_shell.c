#include <stdio.h>
#include <unistd.h>
int main()
{
	char *buffer;
	size_t n;
	ssize_t ch;

	printf("$ ");
	ch = getline(&buffer, &n, stdin);
	printf("%s", buffer);
	printf("the number of character read is %ld\n", ch);
	return (0);
}
