#include "monty.h"
#include <string.h>
/**
 * push_stack - pushes an element onto a stack.
 * @stack: pointer to the pointer to the stack.
 * @line_num: The line number of the push operation.
 */
void push_stack(stack_t **stack, unsigned int line_num)
{
	/* create a new stack node */
	stack_t *new_node = malloc(sizeof(stack_t));

	/* Check if the stack and arguments are valid */
	if (!stack)
	{
		fprintf(stderr, "L%u: Error: stack not found\n", line_num);
		exit(EXIT_FAILURE);
	}

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* Assign values to the new node */
	new_node->n = line_num;
	new_node->prev = NULL;
	new_node->next = *stack;
	/* update the previous top elements's prev pointer */
	if (*stack)
		(*stack)->prev = new_node;
	/* Update the stack pointer to point to the new top element */
	*stack = new_node;
}
/**
 * pop_stack - Remove the top element of the stack.
 * @stack: Pointer to the pointer to the stack.
 * @line_num: The line number of the opo operation.
 */
void pop_stack(stack_t **stack, unsigned int line_num)
{
	/* Assign a temp pointer for **stack  */
	stack_t *temp = *stack;

	/* Check if stack is valid */
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: Error: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	/* update the stack pointer to point to the next element */
	*stack = temp->next;
	/* Free the current top element */
	free(temp);
}
/**
 * free_stack - Free memory allocated to a node
 * @stack: Pointer to the stack pointer
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}
