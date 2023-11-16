#include "monty.h"
#include <stdio.h>

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number in the Monty byte code file
 * Description: this function swaps the top two elements of the stack
 * If the stack contains less than two elements,
 * an error message is printed
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
