#include "push_swap.h"

int	fill_stack_from_numbers(char **numbers, t_node **a)
{
	int		i;
	int		value;
	t_node	*new_node;

	i = 0;
	if (!numbers || !numbers[0])
		return (free_args(numbers), 0);
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
	if (*a == NULL)
		return (0);
	return (1);
}

int	parse_and_fill_stack(int argc, char **argv, t_node **a)
{
	char	**numbers;

	numbers = NULL;
	if (argc == 2)
		numbers = ft_split(argv[1], ' ');
	else
		numbers = join_args(argc, argv);
	return (fill_stack_from_numbers(numbers, a));
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

int	is_valid_number(const char *str)
{
	if (!*str)
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	if (!(*str >= '0' && *str <= '9'))
		return (0);
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str != '\0')
		return (0);
	return (1);
}

int	ft_atoi_safe(const char *str, int *out)
{
	long long	result = 0;
	int			sign = 1;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (!is_valid_number(str))
		return (0);
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
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
