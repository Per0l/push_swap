/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:36:27 by aperol-h          #+#    #+#             */
/*   Updated: 2021/10/08 19:06:59 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_swap(t_stack *stack, int op)
{
	int	tmp;

	if ((op == 0 || op == 2) && stack->a.size > 1)
	{
		ft_print_str("sa\n");
		tmp = stack->a.arr[0];
		stack->a.arr[0] = stack->a.arr[1];
		stack->a.arr[1] = tmp;
	}
	else if ((op == 1 || op == 2) && stack->b.size > 1)
	{
		ft_print_str("sb\n");
		tmp = stack->b.arr[0];
		stack->b.arr[0] = stack->b.arr[1];
		stack->b.arr[1] = tmp;
	}
}

void	ps_push(t_stack *stack, int op)
{
	int	i;

	if (op && stack->b.size > 0)
	{
		ft_print_str("pa\n");
		i = stack->a.size++;
		while (i-- > 0)
			stack->a.arr[i + 1] = stack->a.arr[i];
		stack->a.arr[0] = stack->b.arr[0];
		while (i++ < stack->b.size - 2)
			stack->b.arr[i] = stack->b.arr[i + 1];
		stack->b.size--;
	}
	else if (!op && stack->a.size > 0)
	{
		ft_print_str("pb\n");
		i = stack->b.size++;
		while (i-- > 0)
			stack->b.arr[i + 1] = stack->b.arr[i];
		stack->b.arr[0] = stack->a.arr[0];
		while (i++ < stack->a.size - 2)
			stack->a.arr[i] = stack->a.arr[i + 1];
		stack->a.size--;
	}
}

void	ps_rotate(t_stack *stack, int op)
{
	int	tmp;
	int	i;

	if ((op == 0 || op == 2) && stack->a.size > 1)
	{
		if (op != 2)
			ft_print_str("ra\n");
		tmp = stack->a.arr[0];
		i = -1;
		while (i++ < stack->a.size - 2)
			stack->a.arr[i] = stack->a.arr[i + 1];
		stack->a.arr[i] = tmp;
	}
	if ((op == 1 || op == 2) && stack->b.size > 1)
	{
		if (op != 2)
			ft_print_str("rb\n");
		tmp = stack->b.arr[0];
		i = -1;
		while (i++ < stack->b.size - 2)
			stack->b.arr[i] = stack->b.arr[i + 1];
		stack->b.arr[i] = tmp;
	}
	if (op == 2)
		ft_print_str("rr\n");
}

void	ps_rev_rotate(t_stack *stack, int op)
{
	int	tmp;
	int	i;

	if ((op == 0 || op == 2) && stack->a.size > 1)
	{
		if (op != 2)
			ft_print_str("rra\n");
		i = stack->a.size;
		tmp = stack->a.arr[i - 1];
		while (i-- > 0)
			stack->a.arr[i + 1] = stack->a.arr[i];
		stack->a.arr[0] = tmp;
	}
	if ((op == 1 || op == 2) && stack->b.size > 1)
	{
		if (op != 2)
			ft_print_str("rrb\n");
		i = stack->b.size;
		tmp = stack->b.arr[i - 1];
		while (i-- > 0)
			stack->b.arr[i + 1] = stack->b.arr[i];
		stack->b.arr[0] = tmp;
	}
	if (op == 2)
		ft_print_str("rrr\n");
}

int	ps_exec(t_stack *stack, char *op)
{
	if (ft_streq(op, "sa"))
		ps_swap(stack, 0);
	else if (ft_streq(op, "sb"))
		ps_swap(stack, 1);
	else if (ft_streq(op, "ss"))
		ps_swap(stack, 2);
	else if (ft_streq(op, "pa"))
		ps_push(stack, 1);
	else if (ft_streq(op, "pb"))
		ps_push(stack, 0);
	else if (ft_streq(op, "ra"))
		ps_rotate(stack, 0);
	else if (ft_streq(op, "rb"))
		ps_rotate(stack, 1);
	else if (ft_streq(op, "rr"))
		ps_rotate(stack, 2);
	else if (ft_streq(op, "rra"))
		ps_rev_rotate(stack, 0);
	else if (ft_streq(op, "rrb"))
		ps_rev_rotate(stack, 1);
	else if (ft_streq(op, "rrr"))
		ps_rev_rotate(stack, 2);
	else
		return (0);
	return (1);
}
