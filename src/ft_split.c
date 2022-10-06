/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 12:31:51 by aperol            #+#    #+#             */
/*   Updated: 2021/10/16 17:35:14 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*ft_realloc(void *ptr, size_t ori_size, size_t size)
{
	void	*new;

	if (!ptr)
	{
		new = malloc(size);
		if (!new)
			return (NULL);
	}
	else
	{
		if (ori_size < size)
		{
			new = malloc(size);
			if (!new)
				return (NULL);
			ft_memcpy(new, ptr, ori_size);
			free(ptr);
		}
		else
			new = ptr;
	}
	return (new);
}

static size_t	get_str_arr_len(char **arr)
{
	size_t	i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}

static char	**add_str_toarr(char **arr, char const *str, size_t len, int sidx)
{
	size_t	clen;

	clen = get_str_arr_len(arr) * sizeof(*arr);
	arr = (char **)ft_realloc(arr, clen, clen + (sizeof(char *) * 2));
	if (arr == NULL)
		return (NULL);
	clen /= sizeof(*arr);
	arr[clen] = (char *)malloc((len + 1) * sizeof(char));
	if (!arr[clen])
		return (NULL);
	ft_strlcpy(arr[clen], str + sidx, len + 1);
	arr[clen + 1] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char		**arr;
	size_t		i;
	size_t		lst_i;

	if (!s)
		return (NULL);
	arr = malloc(sizeof(char *));
	if (arr == NULL)
		return (NULL);
	*arr = NULL;
	i = 0;
	lst_i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (i != lst_i)
				arr = add_str_toarr(arr, s, i - lst_i, lst_i);
			lst_i = i + 1;
		}
		i++;
	}
	if (i > 0 && !(s[i - 1] == c))
		arr = add_str_toarr(arr, s, i - lst_i, lst_i);
	return (arr);
}
