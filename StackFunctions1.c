#include "monty.h"
/**
 * StackAdding - add a new node to the stack
 * @stack: pointer to the top of the stack
 * @line_number: the line number of file being processed
 */
void StackAdding(stack_t **NewNode, unsigned int line_number)
{
	stack_t *temp;
	(void) line_number;

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
	head = *NewNode;
	head->next = temp;
	temp->prev = head;
}
/**
 * StackPrint - prints the elemnets of the stack
 * @stack: pointer to the top of the stack
 * @line_number: the line number of file being processed
 */
void StackPrint(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void) line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * StackTopPrint - prints the value of the top stack
 * @stack: pointer to the top of the stack
 * @line_number: the line number of file being processed
 */
void StackTopPrint(stack_t **stack, unsigned int line_number)
{
	int value;

	if (*stack == NULL)
	{
		HandleError("can't pint, stack empty", line_number);
	}
	else
	{
		value = (*stack)->n;
		printf("%d\n", value);
	}
}
/**
 * StackTopRemove - removes the top elemenet of the stack
 * @stack: pointer to the top of the stack
 * @line_number: the line number of file being processed
 */
void StackTopRemove(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		HandleError("can't pop and empty stack", line_number);
		return;
	}
	temp = *stack;
	*stack = temp->next;
	free(temp);
}
/**
 * StackSwap - swaps the top two elemnets of the stack
 * @stack: pointer to the top of the stack
 * @line_number: the line number of the file being processed
 */
void StackSwap(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		HandleError("can't swap, stack too short", line_number);
		return;
	}
	first = *stack;
	second = first->next;

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
