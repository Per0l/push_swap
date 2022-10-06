/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 01:44:26 by aperol-h          #+#    #+#             */
/*   Updated: 2021/10/15 23:24:10 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ft_print_str(char *s)
{
	if (ft_streq(s, "sa\n") || ft_streq(s, "sb\n") || ft_streq(s, "ss\n")
		|| ft_streq(s, "pa\n") || ft_streq(s, "pb\n") || ft_streq(s, "ra\n")
		|| ft_streq(s, "rb\n") || ft_streq(s, "rr\n") || ft_streq(s, "rra\n")
		|| ft_streq(s, "rrb\n") || ft_streq(s, "rrr\n"))
		return ;
	while (*s)
		write(1, s++, 1);
}

void	read_stdin(t_stack *stack)
{
	char	buf;
	char	cmd[5];
	int		i;

	i = 0;
	while (read(0, &buf, 1))
	{
		if (buf == '\n' || i >= 4)
		{
			cmd[i] = '\0';
			i = 0;
			if (!ps_exec(stack, cmd))
			{
				ft_print_str("Error\n");
				return ;
			}
		}
		else
			cmd[i++] = buf;
	}
	if (check_finished(stack))
		ft_print_str("OK\n");
	else
		ft_print_str("KO\n");
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (setup_stack(argc, argv, &stack) == 0)
		return (0);
	read_stdin(&stack);
	free(stack.a.arr);
	free(stack.b.arr);
	free(stack.sorted);
}
