#include "monty.h"
/**
 * FindFunction - finds the appropriate function
 * @parsed: array of string containing the parsed value
 * Return: returns a pointer to the function
 */
void FindFunction(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

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
	if (opcode[0] == '#')
	{
		return;
	}
	for (flag = 1, i = 0; functions_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, functions_list[i].opcode) == 0)
		{
			FunctionCaller(functions_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
	{
		exit(EXIT_FAILURE);
	}
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
/**
 *
 *
 *
 *
 */
void FunctionCaller(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *NewNode;
	int flag = 1, i;

	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
		{
			exit(EXIT_FAILURE);
		}
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
			{
				exit(EXIT_FAILURE);
			}
		}
		NewNode = NodeCreate(atoi(val) * flag);
		if (format == 0)
		{
			func(&NewNode, ln);
		}
		if (format == 1)
		{
			StackQueueAdd(&NewNode, ln);
		}
	}
	else
		func(&head, ln);
}
/**
 *
 *
 *
 *
 */
stack_t *NodeCreate(int n)
{
	stack_t *NewNode;

	NewNode = malloc(sizeof(stack_t));
	if (NewNode == NULL)
	{
		exit(EXIT_FAILURE);
	}
	NewNode->next = NULL;
	NewNode->prev = NULL;
	NewNode->n = n;
	return (NewNode);
}
/**
 *
 *
 *
 */
void StackQueueAdd(stack_t **NewNode, unsigned int ln)
{
	stack_t *temp;
	(void) ln;

	if (NewNode == NULL || *NewNode == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (head == NULL)
	{
		head = *NewNode;
		return;
	}
	temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *NewNode;
	(*NewNode)->prev = temp;
}
