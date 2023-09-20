#include "monty.h"

/**
 * op_pstr - prints the string starting at the top of the stack,
 * followed by a new line
 * @head: Pointer to the head of the stack
 * @counter: line number
 * Return: no return
 */

void op_pstr(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
