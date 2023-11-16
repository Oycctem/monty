#include "monty.h"
/**
 *
 *
 *
 */
void CharPrint(stack_t **stack, unsigned int line_number)
{
	if (*stacl == NULL)
	{
		HandleError("can't pchar, stack empty", line_number);
		return;
	}
	int ascii_value = (*stack)->n;
	if (ascii_value < 0 || ascii_value > 127)
	{
		HandleError("can't pchar, value out of range", line_number);
		return;
	}
	putchar(ascii_value);
	putchar('\n');
}
/**
 *
 *
 *
 *
 */
void StringPrint(stack_t **stack)
{
	stack_t *current = *stack;
	while (current != NULL && current->n != 0 && current->n 0 && current-> <= 127)
	{
		putchar(current->n);
		current = current->next;
	}
	putchar('\n');
}
/**
 *
 *
 *
 *
 */
void rot1(stack_t **stack)
{
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
 *
 *
 *
 */
void rotr(stack_t **stack)
{
	if (*stack != NULL && (*stack)->next != NULL)
	{
		stack_t *last = *stack;
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
