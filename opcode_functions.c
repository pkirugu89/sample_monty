#include "monty1.h"

/**
 * find_instruction - finding the appropriate opcode function.
 * @str: opcode string to search for.
 * Return: Pointer to the coresponding instruction_t struct,
 *        NUll if not found.
 */
void (*find_instruction(char *str))(stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t instruction_s[] = {
		{"push", push_opcode},
		{"pall", pall_opcode},
		{NULL, NULL}
	};

	for (i = 0; instruction_s[i].opcode != NULL; i++)
	{
		/*printf("Comparing: %s to %s\n", opcode, instruction_s[i].opcode);*/
		if (strcmp(str, instruction_s[i].opcode) == 0)
		{
			return (instruction_s[i].f);
		}
	}
	/* opcode not found */
	return (NULL);
}
/**
 * push_opcode - Pushes an element onto the stack.
 * @stack: Pointer to the stack pointer.
 * @line_number: line number of the push operator
 */
void push_opcode(stack_t **stack, unsigned int line_number)
{
	int value;

	if (!gl.arg)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (gl.arg[value] != '\0')
	{
		if (!isdigit(gl.arg[value]) && gl.arg[value] != '-')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		value++;
	}
	value = atoi(gl.arg);
	add_dnodeint(stack, value);
}
/**
 * pall_opcode - Prints all elements in a stack
 * @stack: Pointer to the stack pointer
 * @line_number: Line number of the pall operations
 */
void pall_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
