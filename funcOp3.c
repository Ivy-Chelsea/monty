#include "monty.h"

/**
 * _rotr - rotates the stack to the bottom
 * @stack: pointer to the first node pointer
 * @line_number: file line number
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;
	
	(void)line_number;
}

/**
 * _queue - converts stack to queue
 * @stack: pointer to first node pointer
 * @line_number: current line number
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number
}
