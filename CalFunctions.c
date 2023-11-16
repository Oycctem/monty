#include "monty.h"
/**
 *
 *
 *
 */
void StackAdd(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		HandleError("can't add, stack too short", line_number);
		return;
	}
	stack_t *first = *stack;
	stack_t *second = first->next;
	second->n += first->n;
	*stack = second;
	second->prev = NULL;
	free(first);
}
/**
 *
 *
 *
 *
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
 *
 *
 *
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
 *
 *
 *
 *
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
 *
 *
 *
 */
void StackMod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		HandleError("can't mod, stack too short", line_number);
		return;
	}
	if ((*stacl)->n == 0)
	{
		HandleError("division by zero", line_number);
		return;
	}
	(*stack)->next->n %= (*stack)->n;
	StackTopRemove(stack, line_number);
}
