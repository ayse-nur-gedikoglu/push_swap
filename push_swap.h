#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"


typedef struct s_node
{
	int				index;
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

int		parse_and_fill_stack(int argc, char **argv, t_node **a);
int		fill_stack_from_numbers(char **numbers, t_node **a);
char	**join_args(int argc, char **argv);
int		ft_atoi_safe(const char *str, int *out);
int		has_duplicate(t_node *stack, int value);
int		is_valid_number(const char *str);

void	append_node(t_node **stack, t_node *new_node);
t_node	*create_node(int value);

void	free_args(char **args);
void	free_stack(t_node **stack);
int		is_sorted(t_node *stack);
void	error_and_exit(t_node **a, t_node **b);

void	assign_indexes(t_node *a);
int		get_max_bits(t_node *a);
void	radix_sort(t_node **a, t_node **b);
int		stack_size(t_node *stack);
void	sort_two(t_node **a);
void	sort_three(t_node **a);
void	sort_five(t_node **a, t_node **b);

void	ft_sa(t_node **a, int flg);
void	ft_sb(t_node **b, int flg);
void	ft_ss(t_node **a, t_node **b);

void	ft_pa(t_node **a, t_node **b);
void	ft_pb(t_node **a, t_node **b);

void	ft_ra(t_node **a, int flg);
void	ft_rb(t_node **b, int flg);
void	ft_rr(t_node **a, t_node **b);

void	ft_rra(t_node **a, int flg);
void	ft_rrb(t_node **b, int flg);
void	ft_rrr(t_node **a, t_node **b);

#endif