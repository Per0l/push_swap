/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:18:55 by aperol-h          #+#    #+#             */
/*   Updated: 2021/10/16 18:32:53 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	join_aux(int *i, int argc, char **argv, char **ret)
{
	char	*temp;
	char	*aux;

	temp = ft_strjoin(argv[*i], " ");
	if (*i < argc - 1)
	{
		aux = ft_strjoin(temp, argv[++*i]);
		free(temp);
		temp = ft_strjoin(aux, " ");
		free(aux);
	}
	if (*ret)
	{
		aux = ft_strjoin(*ret, temp);
		free(temp);
		free(*ret);
		*ret = aux;
	}
	else
		*ret = temp;
}

char	*join_args(int argc, char **argv)
{
	int		i;
	char	*ret;

	ret = NULL;
	i = 0;
	while (i++ < argc - 1)
		join_aux(&i, argc, argv, &ret);
	return (ret);
}

int	count_str_arr(char **arr)
{
	int	i;

	if (!arr || !*arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	free_str_arr(char **arr)
{
	int	i;

	if (!arr || !*arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
