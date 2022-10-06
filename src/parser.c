/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:44:57 by aperol-h          #+#    #+#             */
/*   Updated: 2021/10/16 18:37:27 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arr_dup(int *dest, int *src, int size)
{
	int	i;

	i = -1;
	while (i++ < size - 1)
		dest[i] = src[i];
}

void	sort_arr(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	j = -1;
	while (j++ < size - 2)
	{
		i = -1;
		while (i++ < size - 2 - j)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
		}
	}
}

int	check_dup(t_stack *stack)
{
	int	i;

	stack->sorted = (int *)ft_pmalloc(stack->a.size * sizeof(int));
	arr_dup(stack->sorted, stack->a.arr, stack->a.size);
	sort_arr(stack->sorted, stack->a.size);
	i = -1;
	while (i++ < stack->a.size - 2)
	{
		if (stack->sorted[i] == stack->sorted[i + 1])
		{
			free(stack->a.arr);
			free(stack->sorted);
			ft_print_str("Error\n");
			return (1);
		}
	}
	return (0);
}

int	parse_args(int argc, char **argv, t_stack *stack)
{
	int			i;
	long		nbr;

	i = -1;
	stack->a.arr = (int *)ft_pmalloc((argc) * sizeof(int));
	stack->a.size = argc;
	while (i++ < argc - 1)
	{
		nbr = ft_int_atoi(argv[i]);
		if (!(nbr > 2147483647 || nbr < -2147483648))
			stack->a.arr[i] = (int)nbr;
		else
		{
			free(stack->a.arr);
			ft_print_str("Error\n");
			free_str_arr(argv);
			return (0);
		}
	}
	free_str_arr(argv);
	return (1);
}

int	setup_stack(int argc, char **argv, t_stack *stack)
{
	char	**all_args;
	char	*args_union;

	stack->a.col = 'a';
	stack->b.col = 'b';
	if (argc <= 1)
		return (0);
	args_union = join_args(argc, argv);
	all_args = ft_split(args_union, ' ');
	free(args_union);
	if (!parse_args(count_str_arr(all_args), all_args, stack))
		return (0);
	if (check_dup(stack))
		return (0);
	stack->b.arr = (int *)ft_pmalloc((stack->a.size + 1) * sizeof(int));
	if (!stack->b.arr)
		return (0);
	stack->b.size = 0;
	if (check_finished(stack))
		return (1);
	return (2);
}
