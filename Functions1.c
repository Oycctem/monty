#include "monty.h"
/**
 * nope - a placeholder function
 * @stack: pointer to the top of the stack
 * @line_number: line number of the file being processed
 */
void nope(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * HandleError - Handles errors
 * @format: error message formating
 * @...: Additional args to format the message
 */
void HandleError(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);
	exit(EXIT_FAILURE);
}
