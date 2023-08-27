#define _POSIX_C_SOURCE 200809L
#include "monty1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void global(void);
global_t gl;
/**
 * init - intializes global variables.
 * Return: Always (0) Success
 */
void init(void)
{
	gl.buf = NULL;
	gl.count = 1;
	gl.arg = NULL;
	gl.head = 0;
}
/**
 * main - executes the program.
 * @argc: arguments counter.
 * @argv: string arrays of arguments
 * Return: ALways (0) Success.
 */
int main(int argc, char *argv[])
{
	size_t size = 0;
	FILE *file = fopen(argv[1], "r");
	char *opcode[2] = {NULL, NULL};
	void (*f)(stack_t **stack, unsigned int line_number);
	ssize_t size1;

	/* Handle file error checking and argc == 2 */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		free_stack();
		exit(EXIT_FAILURE);
	}
	if (!file)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		free_stack();
		exit(EXIT_FAILURE);
	}
	init();
	size1 = getline(&gl.buf, &size, file);
	while (size1 != -1)
	{
		opcode[0] = strtok(gl.buf, " \n\t");
		if (opcode[0])
		{
			f = find_instruction(opcode[0]);
			if (!f)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", gl.count, opcode[0]);
				free_stack();
				exit(EXIT_FAILURE);
			}
			gl.arg = strtok(NULL, " \n\t");
			f(&gl.head, gl.count);
		}
		size1 = getline(&gl.buf, &size, file);
		gl.count++;
	}
	free_stack();
	fclose(file);
	return (0);
}
