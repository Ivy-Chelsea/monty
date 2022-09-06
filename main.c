#include "monty.h"

globals_t globals;

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: pointer to array of strings
 * Return: EXIT_SUCCESS
 */
int main(int argc, cahr *argv[])
{
	stack_t *stack;

	stack = NULL;
	parse_arg(argc, argv);
	read_line(&stack);

	free(globals.lineptr);
	free_stack(stack);
	fclose(globals.fp);
	return (EXIT_SUCCESS);
}
