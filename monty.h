#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/*extern char *global_n;*/
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 *
 *
 *
 *
 */
typedef struct global_param_s
{
	FILE *file;
	char *buffer;
	char *global_n;
}global_param;
extern global_param g_parm;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void executecode(stack_t **stack, char *str,unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
stack_t *add_node(stack_t **head, const int i);
void pall(stack_t **stack, unsigned int line_number);
int is_number(char *string);
void free_stack(stack_t *head);
void pop(stack_t **stack, unsigned int line_number);
#endif

