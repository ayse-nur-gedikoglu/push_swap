#include "push_swap.h"

void	ft_sa(t_node **a, int flg)
{
	int	tmp;

	if (!*a || !(*a)->next)
		return;
	tmp = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = tmp;
	if (flg)
		write(1, "sa\n", 3);
}

void	ft_sb(t_node **b, int flg)
{
	int	tmp;

	if (!*b || !(*b)->next)
		return;
	tmp = (*b)->value;
	(*b)->value = (*b)->next->value;
	(*b)->next->value = tmp;
	if (flg)
		write(1, "sb\n", 3);
}

void	ft_ss(t_node **a, t_node **b)
{
	ft_sa(a, 0);
	ft_sb(b, 0);
	write(1, "ss\n", 3);
}

void	ft_pa(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (!*b)
		return;
	tmp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	tmp->next = *a;
	if (*a)
		(*a)->prev = tmp;
	*a = tmp;
	tmp->prev = NULL;
	write(1, "pa\n", 3);
}
