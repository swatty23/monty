#include "monty.h"

/**
 * print_stack_elements - Prints all elements in the stack
 * @head: Pointer to the head of the stack
 * @counter: Line number (unused)
 * Return: No return value
 */

void print_stack_elements(stack_t **head, unsigned int counter)
{
	stack_t *current;
	(void)counter;

	current = *head;
	if (current == NULL)
		return;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
