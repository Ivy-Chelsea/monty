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
 * _push_q - adds a new node at the end of a list
 * @stack: pointer to first node pointer
 * @line_number: current line number
 */
void push_q(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *current;

	current = *stack;
	new = malloc(sizeof(stack_t));
	if (!new)
		error_handle(stack, line_number, 2);

	new->n = globals.data;
	new->next = NULL;
	if (!*stack)
	{
		new->prev = NULL;
		*stack = new;
	}
	else
	{
		while (current->next)
			current = current->next;
		new->prev = current;
		current->next = new;
	}
}
