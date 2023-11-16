#include "monty.h"
#include <stdio.h>

/**
 * main - entry point for the Monty byte code interpreter
 * @argc: number of command-line arguments
 * @argv: array of command-line arguments
 * Description: This function reads and interprets
 * Monty byte code from a file
 * Return: 0 on success, non-zero on failure
 */
int main(int argc, char *argv[])
{
	int line_number = 0;
	FILE *file = fopen(argv[1], "r");
	stack_t *stack = NULL;
	char opcode[128];

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (file == NULL)
	{
		fprintf(stderr, "Error : Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(opcode, sizeof(opcode), file) != NULL)
	{
		line_number++;

		if (process_command(&stack, opcode, line_number) == 0)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			fclose(file);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
	}
	fclose(file);
	free_stack(stack);

	return (0);
}
#include "monty.h"
/**
 * process_command - process Monty byte code command
 * @stack: double pointer to the beginning of the stack
 * @opcode: Monty byte code operation code
 * @line_number: line number in the Monty byte code file
 * Description: this function processes a Monty byte code command
 * based on the given opcode
 * Return: 1 if the command is processed successfully, 0 on failure
 */
int process_command(stack_t **stack, char *opcode, unsigned int line_number)
{
	(void)stack; /*suppress unused parameter warning*/
	(void)opcode; /*suppress unused parameter warning*/
	(void)line_number; /* suppress unused parameter warning*/

	return (1);
}

#include "monty.h"
/**
 * free_stack - free the memory allocated for the stack
 * @stack: pointer to the beginning of the stack
 * Description: this function frees the memory allocated for each
 * node in the stack and sets the stack pointer to NULL.
 */
void free_stack(stack_t *stack)
{
	while (stack != NULL)
	{
		stack_t *temp = stack;

		stack = stack->next;
		free(temp);
	}
}
