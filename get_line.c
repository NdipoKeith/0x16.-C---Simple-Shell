#include "shell.h"
int getline()
{
	static char buffer[BUFFER_SIZE];
	static int buffer_pos, buffer_size;
	char input_str = NULL;
	char current_char;
	int input_len = 0;

	while (1)
	{
		if (buffer_pos >=  buffer_size)
		{
			buffer_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_size == 0)
				return (input_str);
			else if (buffer_size < 0)
			{
				perror("read");
				return (NULL);
			}
		}
			current_char = buffer(buffer_pos);
			buffer_pos++;
			if (current_char == '\n')
			{
				input_str = realloc(input_str, input_len + 1);
				input_str[input_len] = '\0'
					return (input_str);
			}
			else
			{
				input_str = realloc(input_str, input_len + 1);
				input_str[input_len] = current_char;
				input_len++;
			}
			return (0);
	}
}
