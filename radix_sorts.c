#include "push_swap.h"

static int *stack_to_array(t_node *a, int size)
{
	int *arr;
	int i = 0;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	while (a)
	{
		arr[i++] = a->value;
		a = a->next;
	}
	return (arr);
}

static void sort_array(int *arr, int size)
{
	int i;
	int j;
	int tmp;

    i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int get_index(int value, int *sorted, int size)
{
	int i = 0;
	while (i < size)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void assign_indexes(t_node *a)
{
	int *sorted;
	int size = stack_size(a);

	sorted = stack_to_array(a, size);
	if (!sorted)
		error_and_exit(&a, NULL);
	sort_array(sorted, size);
	while (a)
	{
		a->index = get_index(a->value, sorted, size);
		a = a->next;
	}
	free(sorted);
}

int get_max_bits(t_node *a)
{
	int max = 0;
	int bits = 0;

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

void radix_sort(t_node **a, t_node **b)
{
	int i = 0;
	int j;
	int size = stack_size(*a);
	int max_bits = get_max_bits(*a);

	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*a)->index >> i) & 1)
				ft_ra(a, 1);
			else
				ft_pb(a, b);
			j++;
		}
		while (*b)
			ft_pa(a, b);
		i++;
	}
}
