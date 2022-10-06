/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_solver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:24:08 by aperol-h          #+#    #+#             */
/*   Updated: 2021/10/15 23:11:07 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_solver(t_stack *stack)
{
	if (stack->a.size == 1)
		return ;
	if (stack->a.arr[0] > stack->a.arr[1])
	{
		if (stack->a.size == 3 && stack->a.arr[1] < stack->a.arr[2]
			&& stack->a.arr[2] < stack->a.arr[0])
		{
			ps_exec(stack, "ra");
			return ;
		}
		ps_exec(stack, "sa");
		if (stack->a.size == 2)
			return ;
	}
	if (stack->a.arr[1] > stack->a.arr[2])
	{
		if (stack->a.arr[2] > stack->a.arr[0])
		{
			ps_exec(stack, "ra");
			ps_exec(stack, "sa");
		}
		ps_exec(stack, "rra");
	}
}

void	four_solver(t_stack *stack)
{
	int	j;

	j = get_idx_arr(stack->a.arr, stack->sorted[0], stack->a.size);
	get_nbr(stack, &stack->a, j);
	ps_exec(stack, "pb");
	three_solver(stack);
	ps_exec(stack, "pa");
}

void	five_solver(t_stack *stack)
{
	int	median;

	median = stack->sorted[2];
	while (stack->b.size < 2)
	{
		if (stack->a.arr[0] < median)
			ps_exec(stack, "pb");
		else
			ps_exec(stack, "ra");
	}
	three_solver(stack);
	if (stack->b.arr[0] < stack->b.arr[1])
		ps_exec(stack, "sb");
	ps_exec(stack, "pa");
	ps_exec(stack, "pa");
}
