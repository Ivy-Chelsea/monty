#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

/* global opcode tokens */
extern char **op_toks;

/**
 * struct stack_s - oubly linked list representation of a stack/queue
 * @n: integer
 * @prev: points to previous element of the stack/queue
 * @next: points to next element of the stack/queue
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

/* primary interpreter functions */
void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t **stack);
void free_tokens(void);
unsigned int token_arr_len(void);
int run_monty(FILE *cript_fd);
void error_set(int error_code);

/* funcOp0 */
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _stack(stack_t *stack);
void pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);

/* funcOp1 */
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _divide(stack_t **stack, unsigned int line_number);

/* funcOp2 */
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);

/* funcOp3 */
void _rotr(stack_t **stack, unsigned int line_number);
void _queue(stack_t **stack, unsigned int line_number);

/* custom standard library functions */
char **strtow(char *str, char *delims);
char *get_int(int n);

/* error messages */
int usage_error(void);
int malloc_error(void);
int f_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int pint_error(unsigned int line_number);
int short_stack_error(unsigned int line_number, char *op);
int divide_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);

#endif
