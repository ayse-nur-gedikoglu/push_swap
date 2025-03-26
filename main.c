#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a = NULL;
	t_node	*b = NULL;
	int		size;

	if (argc < 2)
		return (0);
	if (!parse_and_fill_stack(argc, argv, &a))
		error_and_exit(&a, &b);
	assign_indexes(a);
	if (is_sorted(a))
		return (free_stack(&a), 0);
	size = stack_size(a);
	if (size == 2)
		sort_two(&a);
	else if (size == 3)
		sort_three(&a);
	else if (size <= 5)
		sort_five(&a, &b);
	else
		radix_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

