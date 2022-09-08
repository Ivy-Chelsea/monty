#include "monty.h"

/**
 * _push - adds a new node at the beginning of a list
 * @stack: pointer to pointer of first node
 * @line_number: line number in the file
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new;
	int j;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		error_set(malloc_error());
		return;
	}
	
	if (op_toks[1] == NULL)
	{
		error_set(no_int_error(line_number));
		return;
	}
	
	for (j = 0; op_toks[1][j]; j++)
	{
		if (op_toks[1][j] == '-' && j == 0)
			continue;
		if (op_toks[1][j] < '0' || op_toks[1][j] > '9')
		{
			error_set(no_int_error(line_number));
			return;
		}
	}
	new->n = atoi(op_toks[1]);
	
	if (check_mode(*stack) == STACK)
	{
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
}

/**
 * _pall - prints all elements of a linked list
 * @stack: pointer to pointer to first node of linked list
 * @line_number: the line number in the file
 */
void _pall(stack_t **stack, unsigned int line_number)
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
 * _stack - converts a queue to a stack
 * @stack: pointer to pointer of the first node
 */
void _stack(stack_t *stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}
/**
 * _pint - prints value at the top of the stack
 * @stack: pointer to pointer of the first node
 * @line_number: file line number
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		error_set(pint_error(line_number));
		return;
	}
	
	printf("%d\n", (*stack)->next->n);
}

/**
 * _pop - removes the top element of the stack
 * @stack: pointer to pointer of the first node
 * @line_number: file line number
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		error_set(pop_error(line_number));
		return;
	}
	
	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}
