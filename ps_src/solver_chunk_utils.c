/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_chunk_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:23:15 by aperol-h          #+#    #+#             */
/*   Updated: 2021/10/15 22:49:40 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_s_biggest_arr(t_list *stack)
{
	int		i;
	int		nbr;
	int		last;

	nbr = INT32_MIN;
	i = -1;
	while (i++ < stack->size - 1)
	{
		if (stack->arr[i] > nbr)
		{
			last = nbr;
			nbr = stack->arr[i];
		}
		else if (stack->arr[i] > last)
			last = stack->arr[i];
	}
	return (last);
}

int	get_next_nbr_in_chunk(t_stack *stack, t_chunk *chunk, t_list *col)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (i++ < (col->size - 1))
	{
		if (get_idx_arr(chunk->s_arr, col->arr[i], chunk->size) != -1)
		{
			j = i;
			i = -1;
			while (i++ < j - 1)
				ps_exec(stack, "ra");
			return (1);
		}
	}
	return (0);
}

int	is_top_in_chunk(t_chunk *chunk, int nbr)
{
	int	median;

	sort_arr(chunk->s_arr, chunk->size);
	median = chunk->s_arr[chunk->size / 2];
	if (nbr < median)
		return (0);
	return (1);
}

int	get_nbr_aux(t_stack *stack, t_list *col, char *cmd_p, int idx)
{
	int	i;
	int	shouldSwap;

	shouldSwap = 0;
	i = -1;
	while (i++ < idx - 1)
	{
		ps_exec(stack, cmd_p);
		if (!shouldSwap && col->col == 'b')
		{
			if (!(get_s_biggest_arr(col) == col->arr[0]))
				continue ;
			ps_exec(stack, "pa");
			shouldSwap = 1;
			if (cmd_p[1] != 'r')
				i++;
		}
	}
	return (shouldSwap);
}

int	get_nbr(t_stack *stack, t_list *col, int idx)
{
	int		i;
	char	cmd[4];
	char	*cmd_p;

	cmd[0] = 'r';
	cmd[1] = 'r';
	cmd[2] = col->col;
	cmd[3] = '\0';
	cmd_p = cmd;
	i = -1;
	if (idx <= col->size / 2)
		cmd_p++;
	else
		idx = col->size - idx;
	return (get_nbr_aux(stack, col, cmd_p, idx));
}
