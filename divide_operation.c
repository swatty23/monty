#include "monty.h"

/**
 * divide_top_two_elements - Divides the top two
 * elements of the stack.
 * @head: Pointer to the stack's head
 * @counter: Line number in the Monty bytecode file
 * Return: No return value
 */

void divide_top_two_elements(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	current = *head;

	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	temp_value = current->next->n / current->n;
	current->next->n = temp_value;
	*head = current->next;
	free(current);
}
