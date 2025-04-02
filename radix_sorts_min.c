#include "push_swap.h"

static t_node *find_min_node(t_node *a)
{
	t_node *min;

	min = a;
	while (a)
	{
		if (a->value < min->value)
			min = a;
		a = a->next;
	}
	return (min);
}

static void	rotate_min_to_top(t_node **a, int pos, int size)
{
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			ft_ra(a, 1);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			ft_rra(a, 1);
			pos++;
		}
	}
}

static void	push_min_to_b(t_node **a, t_node **b, int size)
{
	t_node	*min;
	t_node	*tmp;
	int		pos;

	while (size > 3)
	{
		min = find_min_node(*a);
		tmp = *a;
		pos = 0;
		while (tmp != min)
		{
			pos++;
			tmp = tmp->next;
		}
		rotate_min_to_top(a, pos, size + 1);
		ft_pb(a, b);
		size--;
	}
}

void	sort_five(t_node **a, t_node **b)
{
	int	size;

	size = stack_size(*a);
	push_min_to_b(a, b, size);
	sort_three(a);
	while (*b)
		ft_pa(a, b);
}
