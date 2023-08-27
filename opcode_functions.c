#include "monty.h"
#include <stdlib.h>

instruction_t instruction_s[] = {
	{"push", push_opcode},
	{"pop", pop_opcode},
	{"pall", pall_opcode},
	{NULL, NULL}
};
/**
 * push - Pushes an element onto the stack.
 * @stack: Pointer to the pointer to the stack.
 * @line_num: The line number of the push operation.
 */
void push_opcode(stack_t **stack, unsigned int line_num)
{
	char *arg = strtok(NULL, " \n\t");
	int value;
	stack_t *new_node = malloc(sizeof(stack_t));

	/* Debug: print the tokenized argument */
	if (arg)
		printf("Tokenized argument: '%s'\n", arg);
	else
		printf("Tokenized argument is NULL\n");
	/* check if the stack and arguments are valid */
	if (!stack)
	{
		fprintf(stderr, "L%u: Error: stack not found\n", line_num);
		exit(EXIT_FAILURE);
	}

	if (!arg || !is_numeric(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	/* convert argument to an integer */
	value = atoi(arg);

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}
/**
 * pall - Prints all the values on the stack.
 * @stack: Pointer to the pointer to the stack.
 * @line_num: The line number of the pall operation.
 */
void pall_opcode(stack_t **stack, unsigned int line_num)
{
	/* Check if the stack is valid */
	if (!stack)
	{
		fprintf(stderr, "L%u: Error: stack not found\n", line_num);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *current = *stack;
		(void)line_num;
		while (current)
		{
			printf("%d\n", current->n);
			current = current->next;
		}
	}
}

/**
 * pop - Remove the top element from the stack.
 * @stack: Pointer to the stack pointer.
 * @line_num: The line number to the pop operation.
 */
void pop_opcode(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;

	/* check if the stack is valid */
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: Error: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	/* Update the stack pointer to point to the next element */
	*stack = temp->next;
	if (*stack)
		(*stack)->prev = NULL;
	/* Free the current top element */
	free(temp);
}

/**
 * find_instruction - finding the appropriate opcode function.
 * @opcode: opcode string to search for.
 * Return: Pointer to the coresponding instruction_t struct,
 * NUll if not found.
 */
instruction_t *find_instruction(char *opcode)
{
	int i;

	for (i = 0; instruction_s[i].opcode; i++)
	{
		printf("Comparing: %s to %s\n", opcode, instruction_s[i].opcode);
		if (strcmp(opcode, instruction_s[i].opcode) == 0)
		{
			return (&instruction_s[i]);
		}
	}
	/* opcode not found */
	return (NULL);
}
