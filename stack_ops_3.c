#include "push_swap.h"

void	ft_rra(t_node **a, int flg)
{
	t_node	*last;
	t_node	*prev_last;

	if (!*a || !(*a)->next)
		return;
	last = *a;
	while (last->next)
		last = last->next;
	prev_last = last->prev;
	prev_last->next = NULL;
	last->next = *a;
	(*a)->prev = last;
	last->prev = NULL;
	*a = last;
	if (flg)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_node **b, int flg)
{
	t_node	*last;
	t_node	*prev_last;

	if (!*b || !(*b)->next)
		return;
	last = *b;
	while (last->next)
		last = last->next;
	prev_last = last->prev;
	prev_last->next = NULL;
	last->next = *b;
	(*b)->prev = last;
	last->prev = NULL;
	*b = last;
	if (flg)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_node **a, t_node **b)
{
	rra(a, 0);
	rrb(b, 0);
	write(1, "rrr\n", 4);
}
