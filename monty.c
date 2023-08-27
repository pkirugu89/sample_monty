#define _POSIX_C_SOURCE 200809L
#include "monty.h"
#include <stdio.h>
/**
 * main - main function in monty.
 * @argc: the number of arguments.
 * @argv: the string arrays of arguments.
 * Return: Always (0) Success.
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	char *filename;
       	char *opcode, *arg;
	FILE *file;
	instruction_t *instruction;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
	file = fopen(filename, "r");
	if (!file)
	{
		fprintf(stderr, "Error: can't open file %s\n", filename);
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		printf("Line %u: %s", line_number, line);  /* Debug: print the line */
		if (strcmp(line, "\n") == 0)
			continue;
		/* Parse the line and extract the opcode and argument */
		opcode = strtok(line, " \n\t");
		arg = strtok(NULL, " \n\t");
		printf("Tokenized arg in push_opcode: '%s'\n", arg);
		if (!opcode)
			continue;  /* Empty line or whitespace, skip it */
		/* Find and call the corresponding opcode function based on opcode */
		instruction = find_instruction(opcode);
		if (!instruction)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			free(line);
			/*fclose(file); */
			free_stack(&stack);
			exit(EXIT_FAILURE);
		}
		instruction->f(&stack, line_number);
		free(arg); /* free memory allocation */
	}
	free(line);
	fclose(file);
	return (0);
}
