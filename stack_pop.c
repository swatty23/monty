#include "monty.h"

/**
 * op_pop - Removes the top element of the stack.
 * @head: Pointer to the stack's head.
 * @counter: Line number in the Monty byte code file.
 * 
 * Return: No return value.
 */

void op_pop(stack_t **head, unsigned int counter)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	*head = temp->next;
	free(temp);
}
