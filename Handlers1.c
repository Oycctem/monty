#include "monty.h"
/**
 *
 *
 *
 */
int ParseLine(char *buffer, int line_number, int format)
{
	char *opcode = NULL;
	char *value = NULL;
	const char *delim = "\n ";

	if (buffer == NULL)
	{
		fprintf(stdeer; "Error: Invalid buffer in line %d\n", line_number);
		exit(EXIT_FAILURE);
	}
	opcode = strtok(buffer, delim);
	if (opcode == NULL)
	{
		return (format);
	}
	value = strtok(NULL, delim);
	if (strcmp(opcode, "stack") == 0)
	{
		return (0);
	}
	if (strcmp(opcode, "queue") == 0)
	{
		return (1);
	}
	FindFunction(opcode, value, line_number, format);
	return (format);
}
