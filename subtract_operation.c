#include "monty.h"

/**
 * subtract_top_two_elements - Subtracts the top
 * two elements of the stack
 * @head: Pointer to the stack's head
 * @counter: Line number in the Monty bytecode file
 * Return: No return value
 */

void subtract_top_two_elements(stack_t **head, unsigned int counter)
{
	stack_t *aux;
	int difference, num_nodes;

       	aux = *head;

	for (num_nodes = 0; aux != NULL; num_nodes++)
		aux = aux->next;

	if (num_nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	aux = *head;
	difference = aux->next->n - aux->n;
	aux->next->n = difference;
	*head = aux->next;
	free(aux);
}
