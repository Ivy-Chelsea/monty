#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * struct globals_s - contains global variables
 * @data: value to initialize nodes
 * @fp: file pointer
 * @lineptr: pointer to a dynamic buffer
 * @token: pointer to next token
 */
typedef struct globals_s
{
	int data;
	FILE *fp;
	char *lineptr, *token;
} globals_t;

extern globals_t globals;

/**
 * struct stack_s - oubly linked list representation of a stack/queue
 * @n: integer
 * @prev: points to previous element of the stack/queue
 * @nexr: points to next element of the stack/queue
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its functions
 * @opcode: opcode
 * @f: function to handle the opcode
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* funcOp0 */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);

/* funcOp1 */
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);

/* funcOp2 */
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);

/* funcOp3 */
void rotr(stack_t **stack, unsigned int line_number);
void push_q(stack_t **stack, unsigned int line_number);

/* monty_check */
void error_check(stack_t **stack, unsigned int line_number);
void check_op(stack_t **stack, unsigned int line_number);
void parse_arg(int argc, char *argv[]);
void read_line(stack_t **stack);
void parse_num(stack_t **stack, unsigned int line_number);

#endif
