#include "push_swap.h"

void	ft_pb(t_node **a, t_node **b)
{
    t_node *tmp;

    if (!*a)
        return;
    tmp = *a;
    *a = (*a)->next;
    if (*a)
        (*a)->prev = NULL;
    tmp->next = *b;
    if (*b)
        (*b)->prev = tmp;
    *b = tmp;
    tmp->prev = NULL;
	write(1, "pb\n", 3);
}
void	ft_ra(t_node **a, int flg)
{
	t_node	*tmp;
	t_node	*last;

	if (!*a || !(*a)->next)
		return;
	tmp = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	tmp->next = NULL;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->prev = last;
	if (flg)
		write(1, "ra\n", 3);
}
void	ft_rb(t_node **b, int flg)
{
	t_node	*tmp;
	t_node	*last;

	if (!*b || !(*b)->next)
		return;
	tmp = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	tmp->next = NULL;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->prev = last;
	if (flg)
		write(1, "rb\n", 3);
}

void	ft_rr(t_node **a, t_node **b)
{
	ft_ra(a, 0);
	ft_rb(b, 0);
	write(1, "rr\n", 3);
}
