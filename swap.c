#include "monty.h"

/**
 * swap - swaps the top elements of the stack
 * @stack: pointer to first node pointer
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
	tmp->n = num;
}
