#include "monty.h"
/**
 * ParseLine - parse and process the line of input
 * @buffer: the input line to be parsed
 * @line_number: the current line being processed
 * @format: the current format
 * Return: returns the updated format
 */
int ParseLine(char *buffer, int line_number, int format)
{
	char *opcode, *val;
	const char *delim = "\n ";

	if (buffer == NULL)
	{
		fprintf(stderr, "Error: Invalid buffer in line %d\n", line_number);
		exit(EXIT_FAILURE);
	}
	opcode = strtok(buffer, delim);
	if (opcode == NULL)
	{
		return (format);
	}
	val = strtok(NULL, delim);
	if (strcmp(opcode, "stack") == 0)
	{
		return (0);
	}
	if (strcmp(opcode, "queue") == 0)
	{
		return (1);
	}
	FindFunction(opcode, val, line_number, format);
	return (format);
}
/**
 * NodesFree - frees all the nodes
 */
void NodesFree(void)
{
	stack_t *temp;

	if (head == NULL)
	{
		return;
	}
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
