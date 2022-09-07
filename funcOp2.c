#include "monty.h"

/**
 * mul - multiplies the second top element with the top element of the stack
 * @stack: pointer to first node pointer
 * @line_number: file line number
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack || !(*stack)->next)
		error_handle(stack, line_number, 10);
	tmp = *stack;
	*stack = (*stack)->next;

	(*stack)->n *= tmp->n;
	free(tmp);
	(*stack)->prev = NULL;
}

/**
 * mod - finds modulo of second top node divided by top node
 * @stack: pointer to first node pointer
 * @line_number: file line number
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack || !(*stack)->next)
		error_handle(stack, line_number, 11);
	if ((*stack)->n == 0)
		error_handle(stack, line_number, 9);
	tmp = *stack;
	*stack = (*stack)->next;

	(*stack)->n %= tmp->n;
	free(tmp);
	(*stack)->prev = NULL;
}

/**
 * pchar - prints the char at the top of the stack
 * @stack: pointer to first node pointer
 * @line_number: file line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
		error_handle(stack, line_number, 12);
	if ((*stack)->n < 0 || (*stack)->n > 127)
		error_handle(stack, line_number, 13);
	printf("%c\n", (*stack)->n);
}

/**
 * pstr - prints string starting at the top of the stack
 * @stack: pointer to first node pointer
 * @line_number: file line_number
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;
	if (!current)
		printf("\n");
	else
	{
		while (current)
		{
			if (current->n <= 0 || current->n > 127)
				break;
			printf("%c", current->n);
			current = current->next;
		}
		printf("\n");
	}
}
/**
 * rotl - rotates the stack to the top
 * @stack: pointer to the first node pointer
 * @line_number: file line number
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	if ((*stack) && (*stack)->next)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (*stack)->prev;
		(*stack)->prev->next = NULL;
		(*stack)->prev->prev = tmp;
		(*stack)->prev = NULL;
	}
}
