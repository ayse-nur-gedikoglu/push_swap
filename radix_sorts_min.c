#include "push_swap.h"

void sort_two(t_node **a)
{
	if ((*a)->value > (*a)->next->value)
		ft_sa(a, 1);
}

void sort_three(t_node **a)
{
	int f = (*a)->value;
	int s = (*a)->next->value;
	int t = (*a)->next->next->value;

	if (f > s && s < t && f < t)
		ft_sa(a, 1);
	else if (f > s && s > t)
	{
		ft_sa(a, 1);
		ft_rra(a, 1);
	}
	else if (f > s && s < t && f > t)
		ft_ra(a, 1);
	else if (f < s && s > t && f < t)
	{
		ft_sa(a, 1);
		ft_ra(a, 1);
	}
	else if (f < s && s > t && f > t)
		ft_rra(a, 1);
}

static t_node *find_min_node(t_node *a)
{
	t_node *min = a;
	while (a)
	{
		if (a->value < min->value)
			min = a;
		a = a->next;
	}
	return (min);
}

void	sort_five(t_node **a, t_node **b)
{
	t_node	*min;
	t_node	*tmp;
	int		pos;
	int		size;

	size = stack_size(*a);
	while (size > 3)
	{
		min = find_min_node(*a);
		pos = 0;
		tmp = *a;
		while (tmp != min)
		{
			pos++;
			tmp = tmp->next;
		}
		if (pos <= size / 2)
			while (pos-- > 0)
				ft_ra(a, 1);
		else
			while (pos++ < size)
				ft_rra(a, 1);
		ft_pb(a, b);
		size--;
	}
	sort_three(a);
	while (*b)
		ft_pa(a, b);
}

