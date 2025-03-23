#include "push_swap.h"
#include "./libft/libft.h"

void	free_stack(t_node **stack)
{
	t_node	*current;
	t_node	*next;

	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

void	error_and_exit(t_node **a, t_node **b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	is_sorted(t_node *stack)
{
	t_node	*current;

	current = stack;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	free_args(char **numbers)
{
	int	i;

	i = -1;
	while (numbers[++i])
		free(numbers[i]);
	free (numbers);
}
