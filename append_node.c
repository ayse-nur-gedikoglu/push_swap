#include "push_swap.h"

void	append_node(t_node **stack, t_node *new_node)
{
	t_node	*current;

	current = *stack;
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		while (current->next)
			current = current->next;
		current->next = new_node;
		new_node->prev = current; 
	}
}

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
