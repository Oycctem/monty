#include "monty.h"
/**
 *
 *
 *
 *
 */
void StackAdding(stack_t **stack, unsigned int line_number, int n)
{
	stack_t *NewNode = malloc(sizeof(stack_t));
	if (!NewNode)
	{
		exit(EXIT_FAILURE);
	}
	NewNode->n = n;
	NewNode->prev = NULL;
	if (*stack != NULL)
	{
		(*stack)->prev = NewNode;
	}
	NewNode->next = *stack;
	*stack = NewNode;
}
/**
 *
 *
 *
 *
 */
void StackPrint(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 *
 *
 *
 *
 *
 */
void StackTopPrint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		HandleError("can't pint, stack empty", line_number);
	}
	else
	{
		printf("%d\n", (*stack)->n=);
	}
}
/**
 *
 *
 *
 *
 */
void StackTopRemove(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		HandleError("can't pop and empty stack", line_number);
		return;
	}
	stack_t *temp = *stack;
	*stack = (*stack)->next;
	free(temp)
}
/**
 *
 *
 *
 *
 */
void StackSwap(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		HandleError("can't swap, stack too short", line_number);
		return;
	}
	stack_t *first = *stack;
	stack_t *second = first->next;

	first->next = second->next;
	second->prev = first->prev;
	second->next = first->prev;
	first->prev = second;

	if (first->next != NULL)
	{
		first->next->prev = first;
	}
	*stack = second;
}
