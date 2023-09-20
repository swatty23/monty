#include "monty.h"

/**
 * swap_top_two_elements - Swaps the top two elements
 * of the stack.
 * @head: Pointer to the stack's head
 * @counter: Line number in the Monty bytecode file
 * Return: No return value
 */

void swap_top_two_elements(stack_t **head, unsigned int counter)
{
	stack_t *current;
	int stack_length = 0, temp_value;

	current = *head;

	while (current)
	{
		current = current->next;
		stack_length++;
	}

	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	current = *head;
	temp_value = current->n;
	current->n = current->next->n;
	current->next->n = temp_value;
}
