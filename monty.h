#ifndef MONTY_H
#define MONTY_H
/* Library imports */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

/* Function prototypes for opcode functions */
/* prototype for adding an element on a stack */
void push_opcode(stack_t **stack, unsigned int line_number);
/* prototype for removing an element from the stack */
void pop_opcode(stack_t **stack, unsigned int line_number);
/* prototype for printing all elements in a stack */
void pall_opcode(stack_t **stack, unsigned int line_number);
/* prototype for finding the appropriate opcode function */
instruction_t *find_instruction(char *opcode);
/* prototype that checks if a str is numeric */
int is_numeric(const char *str);
/* function prototypes for stack functions */
void push_stack(stack_t **stack, unsigned int line_num);
void pop_stack(stack_t **stack, unsigned int line_num);
void free_stack(stack_t **stack);

#endif
