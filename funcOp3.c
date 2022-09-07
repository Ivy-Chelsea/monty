#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack: pointer to the first node pointer
 * @line_number: file line number
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	if ((*stack) && (*stack)->next)
	{
		tmp = *stack;
		while (tmp->next->next)
			tmp = tmp->next;
		(*stack)->prev = tmp->next;
		tmp->next->prev = NULL;
		tmp->next->next = *stack;
		tmp->next = NULL;
		*stack = (*stack)->prev;
	}
}

/**
 * push_q - adds a new node at the end of a list
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

	new->n = global.data;
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
