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
	void (*function)(stack_t **, unsigned int);
	char *tokens[2];
	const char *delim = "\n ";

	if (buffer == NULL)
	{
		fprintf(stderr, "Error: Invalid buffer in line %d\n", line_number);
		exit(EXIT_FAILURE);
	}
	tokens[0] = strtok(buffer, delim);
	if (tokens[0] == NULL)
	{
		return (format);
	}
	tokens[1] = strtok(NULL, delim);
	function = FindFunction(tokens);
	if (function != NULL)
	{
		function(NULL, line_number);
	}
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
