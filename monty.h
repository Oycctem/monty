#ifndef MONTY_h
#define MONTY_h

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void(*op_func)(stack_t **, unsigned int);

void StackAdd(stack_t **stack, unsigned int line_number);
void StackSub(stack_t **stack, unsigned int line_number);
void StackDiv(stack_t **stack, unsigned int line_number);
void StackMul(stack_t **stack, unsigned int line_number);
void StackMod(stack_t **stack, unsigned int linr_number);

void StackAdding(stack_t **stack, unsigned int line_number);
void StackPrint(stack_t **stack, unsigned int line_number);
void StackTopPrint(stack_t **stack, unsigned int line_number);
void StackTopRemove(stack_t **stack, unsigned int line_number);
void StackSwap(stack_t **stack, unsigned int line_number);

void ElementAdd(stack_t **stack, unsigned int line_number);
void nope(stack_t **stack, unsigned int line_number);

void CharPrint(stack_t **stack, unsigned int line_number);
void StrPrint(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

void (*FindFunction(char **parsed))(stack_t **, unsigned int);
void OpenFile(char *file_name);
void ReadFile(FILE *fdes);
int ParseLine(char *buffer, int line_number, int format);

void HandleError(const char *format, ...);
void NodesFree(void);

#endif
