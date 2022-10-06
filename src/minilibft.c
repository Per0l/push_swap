/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:45:22 by aperol-h          #+#    #+#             */
/*   Updated: 2021/10/16 17:36:17 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	check_finished(t_stack *stack)
{
	int	i;

	if (stack->b.size != 0)
		return (0);
	i = -1;
	while (i++ < stack->a.size - 1)
	{
		if (stack->a.arr[i] != stack->sorted[i])
			return (0);
	}
	return (1);
}

long	ft_int_atoi(char *s)
{
	long	nbr;
	char	sig;

	sig = '+';
	nbr = 0;
	while (*s)
	{
		if (*s == '-' || *s == '+')
			sig = *s++;
		if (!(*s >= '0' && *s <= '9'))
			return (2147483648);
		nbr *= 10;
		if (sig == '-')
			nbr -= *s++ - '0';
		else
			nbr += *s++ - '0';
		if (nbr > 2147483647 || nbr < -2147483648)
			return (nbr);
	}
	return (nbr);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

int	ft_streq(char *s1, char *s2)
{
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (*s1 && *s2)
	{
		if (*s1++ != *s2++)
			return (0);
	}
	return (1);
}

void	*ft_pmalloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
		exit(0);
	return (ret);
}
