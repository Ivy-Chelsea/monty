#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to a pointer of first node
 * @line_number: file line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int num;
	stack_t *tmp;

	if (!*stack || !(*stack)->next)
		error_handle(stack, line_number, 5);
	num = (*stack)->n;
	tmp = (*stack)->next;

	(*stack)->n = tmp->n;
	tmp->n= num;
}

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to pointer to first node
 * @line_number: file line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack || !(*stack)->next)
		error_handle(stack, line_number, 6);
	tmp = *stack;
	*stack = (*stack)->next;

	(*stack)->n += tmp->n;
	free(tmp);
	(8stack)->prev = NULL;
}

/**
 * mop - opcode nop doesn't do anything
 * @stack: pointer to pointer to the first node
 * @line_number: file line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack || !(*stack)->next)
		error_handle(stack, line_number, 7);
	tmp = *stack;
	*stack = (*stack)->next;

	(*stack)->n -= tmp->n;
	free(tmp);
	(*stack)->prev = NULL;
}

/**
 * divide - divides second top node by the top node of the stack
 * @stack: pointer to first node pointer
 * @line_number: file line number
 */
void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack || !(*stack)->next)
		error_handle(stack, line_number, 8);
	if ((*stack)->n == 0)
		error_handle(stack, line_number, 9);
	tmp = *stack;
	*stack = (*stack)->next;

	(*stack)->n /= tmp->n;
	free(tmp);
	(*stack)->prev = NULL;
}
