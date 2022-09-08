#include "monty.h"

/**
 * _mul - multiplies the second top element with the top element of the stack
 * @stack: pointer to first node pointer
 * @line_number: file line number
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		error_set(short_stack_error(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	_pop(stack, line_number);
}

/**
 * _mod - finds modulo of second top node divided by top node
 * @stack: pointer to first node pointer
 * @line_number: file line number
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		error_set(short_stack_error(line_number, "mod"));
		retrun;
	}
	
	if ((*stack)->next->n == 0)
	{
		error_set(divide_error(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	_pop(stack, line_number);
}

/**
 * pchar - prints the char at the top of the stack
 * @stack: pointer to first node pointer
 * @line_number: file line number
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		error_set(pchar_error(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		error_set(pchar_error(line_number
					value out of range"));
		return;
	}
	
	printf("%c\n", (*stack)->next->n);
}

/**
 * _pstr - prints string starting at the top of the stack
 * @stack: pointer to first node pointer
 * @line_number: file line_number
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;
	
	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	
	printf("\n");
	
	(void)line_number;
}
/**
 * rotl - rotates the stack to the top
 * @stack: pointer to the first node pointer
 * @line_number: file line number
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;
		
	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;
		
	top->next = *stack;
	(*stack)->next = top->next;
	bottom->next = NULL;
	top->prev = bottom;
	
	(void)line_number;
}
