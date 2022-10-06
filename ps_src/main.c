/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 01:44:26 by aperol-h          #+#    #+#             */
/*   Updated: 2021/10/16 18:41:09 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve(t_stack *stack)
{
	int	chunksize;

	if (stack->a.size <= 3)
		return (three_solver(stack));
	if (stack->a.size == 4)
		return (four_solver(stack));
	if (stack->a.size == 5)
		return (five_solver(stack));
	chunksize = stack->a.size / 6;
	if (stack->a.size > 80 && stack->a.size < 120)
		chunksize = 20;
	else if (stack->a.size > 480 && stack->a.size < 520)
		chunksize = 63;
	solver_chunk(stack, chunksize);
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	int		ret;

	ret = setup_stack(argc, argv, &stack);
	if (ret == 0)
		return (0);
	else if (ret == 2)
	{
		stack.chunks.size = 0;
		stack.chunks.list = NULL;
		solve(&stack);
		ft_lstclear(&stack.chunks.list);
	}
	free(stack.a.arr);
	free(stack.b.arr);
	free(stack.sorted);
}
