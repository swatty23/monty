#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (!current || !current->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	current->next->n += current->n;
	*stack = current->next;
	free(current);
}
