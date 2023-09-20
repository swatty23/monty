#include "monty.h"

/**
 * rotate_stack_left - Rotates the stack to the top
 * @head: Pointer to the stack's head
 * @counter: Line number in the Monty bytecode file (unused)
 * Return: No return value
 */

void rotate_stack_left(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *head, *aux;

       	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}
