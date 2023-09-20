#include "monty.h"

/**
 * queue_mode - Sets the stack to queue mode.
 * @head: Double pointer to the head of the stack.
 * @counter: Line number.
 * Return: No return value.
 */

void queue_mode(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifo = 0;
}

/**
 * add_queue - Adds a new node to the tail of the stack.
 * @n: New value to be added.
 * @head: Double pointer to the head of the stack.
 * Return: No return value.
 */

void add_queue(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
		if (new_node == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
		new_node->n = n;
		new_node->next = NULL;
		if (aux)
		{
			while (aux->next)
				aux = aux->next;
		}
		if (!aux)
		{
			*head = new_node;
			new_node->prev = NULL;
		}
		else
		{
			aux->next = new_node;
			new_node->prev = aux;
		}
}
