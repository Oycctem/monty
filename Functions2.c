#include "monty.h"
/**
 * CharPrint - Prints the char representation of the top stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the file being processed
 */
void CharPrint(stack_t **stack, unsigned int line_number)
{
	int ascii_value = (*stack)->n;

	if (*stack == NULL)
	{
		HandleError("can't pchar, stack empty", line_number);
		return;
	}
	if (ascii_value < 0 || ascii_value > 127)
	{
		HandleError("can't pchar, value out of range", line_number);
		return;
	}
	putchar(ascii_value);
	putchar('\n');
}
/**
 * StrPrint - Prints the char representation of the top stack until a null
 * @stack: pointer to the top of the stack
 * @line_number: line number of the file being processed
 */
void StrPrint(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void) line_number;

	while (current != NULL && current->n >= 0 && current->n <= 127)
	{
		putchar(current->n);
		current = current->next;
	}
	putchar('\n');
}
/**
 * rotl - rotates the stack to the top
 * @stack: pointer to the top of the stack
 * @line_number: line number of the file being processed
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		stack_t *last = *stack;

		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = *stack;
		(*stack)->prev = last;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		last->next->next = NULL;
	}
}
/**
 * rotr - rotate the stack to the bottom
 * @stack: pointer to the top of the stack
 * @line_number: line number of the file being processed
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last;
	(void) line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		last = *stack;
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = *stack;
		(*stack)->prev = last;
		*stack = last->next->next;
		(*stack)->prev = NULL;
		last->next->next = NULL;
	}
}
