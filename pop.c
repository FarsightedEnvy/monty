#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pop - removes the top element of the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number in the Monty byte code file
 * Description: this function removes the top element of the stack
 * If the stack is empty, an error message is printed
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
