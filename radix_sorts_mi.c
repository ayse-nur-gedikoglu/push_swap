#include "push_swap.h"

void sort_two(t_node **a)
{
	if ((*a)->value > (*a)->next->value)
		ft_sa(a, 1);
}

void sort_three(t_node **a)
{
	int x;
	int y;
	int z;

	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	if (x > y && y < z && x < z)
		ft_sa(a, 1);
	else if (x > y && y > z)
	{
		ft_sa(a, 1);
		ft_rra(a, 1); 
	}
	else if (x > y && y < z && x > z)
		ft_ra(a, 1);
	else if (x < y && y > z && x < z)
	{
		ft_sa(a, 1);
		ft_ra(a, 1);
	}
	else if (x < y && y > z && x > z)
		ft_rra(a, 1);
}

int get_max_bits(t_node *a)
{
	int max;
	int bits;

	max = 0;
	bits = 0;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}
