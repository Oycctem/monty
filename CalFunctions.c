#include "monty.h"
/**
 * StackAdd - adds the values of the top two elemnets of the stack
 * @stack: Pointer to the top stack
 * @line_number: line number of the file being processed
 */
void StackAdd(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		HandleError("can't add, stack too short", line_number);
		return;
	}
	first = *stack;
	second = first->next;
	second->n += first->n;
	*stack = second;
	if (second->next != NULL)
	{
	second->next->prev = second;
	}
	free(first);
}
/**
 * StackSub - subtracts the top elements of the stack
 * @stack: pointer to the top stack
 * @line_number: line number of the file being processed
 */
void StackSub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		HandleError("can't sub, stack too short", line_number);
		return;
	}
	(*stack)->next->n -= (*stack)->n;
	StackTopRemove(stack, line_number);
}
/**
 * StackDiv - devides the second top elements by to of the stack
 * @stack: pointer to the top stack
 * @line_number: line number of the file being processed
 */
void StackDiv(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		HandleError("cant div, stack too short", line_number);
		return;
	}
	if ((*stack)->n == 0)
	{
		HandleError("division by zero", line_number);
		return;
	}
	(*stack)->next->n /= (*stack)->n;
	StackTopRemove(stack, line_number);
}
/**
 * StackMul - multiplys the second top element by the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the file being processed
 */
void StackMul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		HandleError("can't mul, stack too short", line_number);
		return;
	}
	(*stack)->next->n *= (*stack)->n;
	StackTopRemove(stack, line_number);
}
/**
 * StackMod - computes the modulo of the second element by the top stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the file being processed
 */
void StackMod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		HandleError("can't mod, stack too short", line_number);
		return;
	}
	if ((*stack)->n == 0)
	{
		HandleError("division by zero", line_number);
		return;
	}
	(*stack)->next->n %= (*stack)->n;
	StackTopRemove(stack, line_number);
}
