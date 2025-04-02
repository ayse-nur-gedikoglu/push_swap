#include "push_swap.h"

static int *stack_to_array(t_node *a, int size)
{
	int *arr;
	int i;

	i = 0;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	while (a)
	{
		arr[i] = a->value;
		a = a->next;
		i++;
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
	int i;

	i = 0;
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
	int size;
	
	size = stack_size(a);
	sorted = stack_to_array(a, size); //burada bir dizi oluşuyor.
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

void radix_sort(t_node **a, t_node **b)
{
	int i;
	int j;
	int size;
	int max_bits;

	i = 0;
	size = stack_size(*a);
	max_bits = get_max_bits(*a);
	while (i < max_bits)
	{
		j = 0;
		while (j < size) //Stack A’deki tüm elemanlar bir kez kontrol edilir.
		{
			if (((*a)->index >> i) & 1) //Eğer bit = 1 → ra → eleman A'da kalır (sadece döner)
				ft_ra(a, 1);
			else
				ft_pb(a, b); //Eğer bit = 0 → pb → eleman B'ye gönderilir
			j++;
		}
		while (*b)
			ft_pa(a, b); //Stack B’ye gönderilen (0’lar) elemanlar tekrar A’ya alınır.
		i++;
	}
}
