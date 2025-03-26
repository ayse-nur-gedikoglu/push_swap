#include "push_swap.h"
#include "./libft/libft.h"

int	parse_and_fill_stack(int argc, char **argv, t_node **a)
{
	char	**numbers;
	int		i;
	int		value;
	t_node	*new_node;

	numbers = NULL;
	i = 0;
	if (argc == 2)
		numbers = ft_split(argv[1], ' ');
	else
		numbers = join_args(argc, argv);
	if (!numbers)
		return (0);
	while (numbers[i])
	{
		if (!ft_atoi_safe(numbers[i], &value))
			return (free_args(numbers), 0);
		if (has_duplicate(*a, value))
			return (free_args(numbers), 0);
		new_node = create_node(value);
		if (!new_node)
			return (free_args(numbers), 0);
		append_node(a, new_node);
		i++;
	}
	free_args(numbers);
	return (1);
}

char	**join_args(int argc, char **argv)
{
	char	*joined;
	char	*temp;
	char	**result;
	int		i;

	joined = ft_strdup(argv[1]);
	if (!joined)
		return (NULL);
	i = 2;
	while (i < argc)
	{
		temp = ft_strjoin(joined, " ");
		free(joined);
		joined = ft_strjoin(temp, argv[i]);
		free(temp);
		if (!joined)
			return(NULL);
		i++;
	}
	result = ft_split(joined, ' ');
	free(joined);
	return (result);
}
int	ft_atoi_safe(const char *str, int *out)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!*str)
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if ((sign == 1 && result > 2147483647)
			|| (sign == -1 && -result < -2147483648))
			return (0);
		str++;
	}
	*out = (int)(result * sign);
	return (1);
}

int	has_duplicate(t_node *stack, int value)
{
	t_node	*current;

	current = stack;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}
