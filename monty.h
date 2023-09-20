#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - Doubly linked list node for stack (or queue) elements
 * @n: Integer value stored in the node
 * @prev: Pointer to the previous element in the stack (or queue)
 * @next: Pointer to the next element in the stack (or queue)
 *
 * Description: This structure represents a node in a doubly linked list
 * used for stack and queue operations in a Monty language interpreter.
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct interpreter_data - Data structure for interpreter variables
 * @arg: Argument value
 * @file: Pointer to the Monty bytecode file
 * @content: Line content from the Monty file
 * @lifi: Flag to switch between stack and queue mode (0 for stack, 1 for queue)
 *
 * Description: This structure stores variables and mode information used
 * throughout the Monty interpreter program.
 */

typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;

/**
 * struct interpreter_data - Data structure for interpreter variables
 * @arg: Argument value
 * @file: Pointer to the Monty bytecode file
 * @content: Line content from the Monty file
 * @lifi: Flag to switch between stack and queue mode (0 for stack, 1 for queue)
 *
 * Description: This structure stores variables and mode information used
 * throughout the Monty interpreter program.
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void add(stack_t **stack, unsigned int line_number);
void push_to_stack(stack_t **head, int n);
void mod_operation(stack_t **head, unsigned int counter);
int execute_opcode(char *content, stack_t **head, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void mul_operation(stack_t **head, unsigned int counter);
void print_stack_elements(stack_t **head, unsigned int counter);
void op_pchar(stack_t **head, unsigned int line_number);
void op_pint(stack_t **head, unsigned int line_number);
void op_pop(stack_t **head, unsigned int counter);
void opcode_push(stack_t **head, unsigned int counter);
void queue_mode(stack_t **head, unsigned int counter);
void add_queue(stack_t **head, int n);
void opcode_rotr(stack_t **head, unsigned int counter);
void print_top_element(stack_t **head, unsigned int counter);
void subtract_top_two_elements(stack_t **head, unsigned int counter);
void swap_top_two_elements(stack_t **head, unsigned int counter);
void divide_top_two_elements(stack_t **head, unsigned int counter);
void do_nothing(stack_t **head, unsigned int counter);
void rotate_stack_left(stack_t **head, __attribute__((unused)) unsigned int counter);
void op_pstr(stack_t **head, unsigned int counter);

#endif
