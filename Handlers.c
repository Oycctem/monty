#include "monty.h"
/**
 * FindFunction - finds the appropriate function
 * @parsed: array of string containing the parsed value
 * Return: returns a pointer to the function
 */
void (*FindFunction(char **parsed))(stack_t **, unsigned int)
{
	int i;

	instruction_t functions_list[] = {
		{"push", StackAdding},
		{"pall", StackPrint},
		{"pint", StackTopPrint},
		{"pop", StackTopRemove},
		{"swap", StackSwap},
		{"nop", nope},
		{"add", StackAdd},
		{"sub", StackSub},
		{"div", StackDiv},
		{"mul", StackMul},
		{"mod", StackMod},
		{"pchar", CharPrint},
		{"pstr", StrPrint},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	for (i = 0; functions_list[i].opcode != NULL; i++)
	{
		if (strcmp(functions_list[i].opcode, parsed[0]) == 0)
		{
			return (functions_list[i].f);
		}
	}
	return (NULL);
}
/**
 * OpenFile - opens a file for reading and caling the ReadFile to process
 * @file_name: name of the file to open
 */
void OpenFile(char *file_name)
{
	FILE *fdes = fopen(file_name, "r");

	if (fdes == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	ReadFile(fdes);
	fclose(fdes);
}
/**
 * ReadFile - reads and processes the contents of the file opened
 * @fdes: pointer to the file
 */
void ReadFile(FILE *fdes)
{
	int line_number = 1;
	int format = 0;
	char *buffer = NULL;
	size_t len = 0;

	while (getline(&buffer, &len, fdes) != -1)
	{
		format = ParseLine(buffer, line_number, format);
		line_number++;
	}
	free(buffer);
}

