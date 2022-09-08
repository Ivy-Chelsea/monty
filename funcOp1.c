#include "monty.h"

/**
 * _swap - swaps the top two elements of the stack
 * @stack: pointer to a pointer of first node
 * @line_number: file line number
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || !(*stack)->next->next == NULL)
	{
		error_set(short_stack_error(line_number, "swap"));
		return;
	}
	
	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}

/**
 * _add - adds the top two elements of the stack
 * @stack: pointer to pointer to first node
 * @line_number: file line number
 */
void _add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		error_set(short_stack_error(line_number, "add"));
		return;
	}
	
	(*stack)->next->next->n += (*stack)->next->n;
	_pop(stack, line_number);
}

/**
 * nop - opcode nop doesn't do anything
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
 * _divide - divides second top node by the top node of the stack
 * @stack: pointer to first node pointer
 * @line_number: file line number
 */
void _divide(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		error_set(short_stack_error(line_number, "divide"));
		return;
	}
	
	if ((*stack)->next->->n == 0)
	{
		error_set(divide_errorline_number));
		return;
	
	}
	
	(*stack)->next->next->n /= (*stack)->next->n;
	_pop(stack, line_number);
}
