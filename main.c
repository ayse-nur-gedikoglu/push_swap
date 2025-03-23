#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (!parse_and_fill_stack(argc, argv, &a))
		error_and_exit(&a, &b);
	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	turk_algorithm(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
