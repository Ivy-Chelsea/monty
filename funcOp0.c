#include "monty.h"

/**
 * push - adds a new node at the beginning of a list
 * @stack: pointer to pointer of first node
 * @line_number: line number in the file
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
		error_handle(stack, line_number, 2);

	new->n = globals.data;
	new->prev = NULL;
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * pall - prints all elements of a linked list
 * @stack: pointer to pointer to first node of linked list
 * @line_number: the line number in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * free_stack - frees a list
 * @stack: pointer to pointer of the first node
 */
void free_stack(stack_t *stack)
{
	stack_t *current;

	while (stack)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
}
/**
 * pint - prints value at the top of the stack
 * @stack: pointer to pointer of the first node
 * @line_number: file line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
		error_handle(stack, line_number, 3);
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: pointer to pointer of the first node
 * @line_number: file line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!(*stack))
		error_handle(stack, line_number, 4);
	tmp = *stack;

	*stack = (*stack)->next;
	free(tmp);
	if (*stack)
		(*stack)->prev = NULL;
}
