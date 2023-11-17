#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point of the code
 * @argc: number of args
 * @argv: args
 * Return: returns 0 if successful
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	OpenFile(argv[1]);
	NodesFree();
	return (0);
}
