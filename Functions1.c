#include "monty.h"
/**
 *
 *
 *
 */
void nope(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
void HandleError(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	vfprintd(stderr, format, args);
	va_end(args);
	exit(EXIT_FAILURE);
}
