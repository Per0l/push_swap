/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_chunk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:26:05 by aperol-h          #+#    #+#             */
/*   Updated: 2021/10/15 22:34:19 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_biggest_arr(t_list *stack)
{
	int		i;
	int		j;
	int		nbr;

	nbr = INT32_MIN;
	i = -1;
	j = 0;
	while (i++ < (stack->size - 1) / 2)
	{
		if (stack->arr[i] > nbr)
		{
			nbr = stack->arr[i];
			j = i;
		}
		if (stack->arr[stack->size - i - 1] > nbr)
		{
			nbr = stack->arr[stack->size - i - 1];
			j = stack->size - i - 1;
		}
	}
	return (j);
}

void	calc_chunks(t_stack *stack, int chunk_size)
{
	int	i;
	int	newsize;

	i = 0;
	while (i * chunk_size <= stack->a.size)
	{
		newsize = stack->a.size - (i * chunk_size);
		if (newsize < chunk_size)
		{
			ft_lstadd_front(&stack->chunks, ft_lstnew(newsize, 'a'));
			arr_dup(stack->chunks.list->s_arr, stack->sorted, newsize);
			return ;
		}
		ft_lstadd_front(&stack->chunks, ft_lstnew(chunk_size, 'a'));
		arr_dup(stack->chunks.list->s_arr,
			stack->sorted + stack->a.size - (chunk_size * (i + 1)), chunk_size);
		i++;
	}
}

void	final_solver(t_stack *stack)
{
	int	swap;

	while (stack->b.size > 0)
	{
		swap = get_nbr(stack, &stack->b, get_biggest_arr(&stack->b));
		ps_exec(stack, "pa");
		if (swap)
			ps_exec(stack, "sa");
	}
}

void	solver_chunk(t_stack *stack, int chunksize)
{
	int	i;
	int	j;
	int	nchunks;

	calc_chunks(stack, chunksize);
	i = -1;
	nchunks = stack->chunks.size;
	while (i++ < nchunks - 1)
	{
		j = -1;
		while (j++ < stack->chunks.list->size - 1)
		{
			get_next_nbr_in_chunk(stack, stack->chunks.list, &stack->a);
			if (is_top_in_chunk(stack->chunks.list, stack->a.arr[0]))
				ps_exec(stack, "pb");
			else
			{
				ps_exec(stack, "pb");
				ps_exec(stack, "rb");
			}
		}
		ft_lsdelfirst(&stack->chunks);
	}
	final_solver(stack);
}
