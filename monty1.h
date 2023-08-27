#ifndef MONTY1_H
#define MONTY1_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <ctype.h>

/**
 *  * struct stack_s - doubly linked list representation of a stack (or queue)
 *   * @n: integer
 *    * @prev: points to the previous element of the stack (or queue)
 *     * @next: points to the next element of the stack (or queue)
 *      *
 *       * Description: doubly linked list node structure
 *        * for stack, queues, LIFO, FIFO
 *         */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 *  * struct instruction_s - opcode and its function
 *   * @opcode: the opcode
 *    * @f: function to handle the opcode
 *     *
 *      * Description: opcode and its function
 *       * for stack, queues, LIFO, FIFO
 *        */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct global
{
	char *buf;
	int count;
	char *arg;
	stack_t *head;
} global_t;
extern global_t gl; /* global variable */

void (*find_instruction(char *str))(stack_t **stack, unsigned int line_number);
void push_opcode(stack_t **stack, unsigned int line_number);
void pall_opcode(stack_t **stack, unsigned int line_number);
/* Prototype that adds a new node at the beginning of dlistint_t list */
stack_t *add_dnodeint(stack_t **head, int n);
/* Prototype that adds a new node at the end of dlistint_t list */
stack_t *add_dnodeint_end(stack_t **head, int n);
/* Prototype that frees a dlistint_t list */
void free_stack_t(stack_t *head);
void free_stack(void);

#endif
