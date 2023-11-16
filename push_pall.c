#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * push - pushes an element onto the stack
 * @stack: double pointer to the beginning of the stack
 * @arg: argument provided with the push opcode
 * @line_number: line number in the Monty byte code file
 * Description: this function pushes an element onto the stack
 */
void push(stack_t **stack, char *arg, unsigned int line_number)
{
	int value;
	stack_t *new_node;

	if (arg == NULL || !is_number(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	value = atoi(arg);

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
/**
 * pall - prints all the values on the stack
 * @stack: pointer to the beginning of the stack
 * Description: this function prints all the values on the stack,
 * starting from the top of the stack
 */

void pall(const stack_t *stack)
{
	const stack_t *temp = stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
