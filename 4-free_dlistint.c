#include "monty1.h"

/**
 * free_stack_t - method that frees the stack_t list
 * @head:  start node
 *
 * Return: Always 0 (Success)
 */
void free_stack_t(stack_t *head)
{
	stack_t *current = head;

	/* Transverse the list and free each node */
	while (current != NULL)
	{
		/* temp dlistint_t stores the current nod */
		stack_t *temp = current;
		/* moves to the next node */
		current = current->next;
		/* Free the stored node */
		free(temp);
	}
}
/**
 * free_stack - Frees memory from buffer
 * Return: Always (0) Success
 */
void free_stack(void)
{
	free_stack_t(gl.head);
	free(gl.buf);
}
