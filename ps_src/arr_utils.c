/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 03:54:39 by aperol-h          #+#    #+#             */
/*   Updated: 2021/10/15 18:17:09 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	del_item_arr(int *arr, int idx, int size)
{
	idx--;
	while (idx++ < size - 2)
		arr[idx] = arr[idx + 1];
}

int	get_idx_arr(int *arr, int nbr, int size)
{
	int	i;

	i = -1;
	while (i++ < size - 1)
	{
		if (arr[i] == nbr)
			return (i);
	}
	return (-1);
}

int	is_nbr_biggest(int *arr, int nbr, int size)
{
	int	i;

	i = -1;
	while (i++ < size - 1)
	{
		if (nbr < arr[i])
			return (0);
	}
	return (1);
}

int	is_nbr_smallest(int *arr, int nbr, int size)
{
	int	i;

	i = -1;
	while (i++ < size - 1)
	{
		if (nbr > arr[i])
			return (0);
	}
	return (1);
}

/* int	is_arr_sorted(int *arr, int n)
{
	if (n == 1 || n == 0)
		return (1);
	if (arr[n - 1] < arr[n - 2])
		return (0);
	return (is_arr_sorted(arr, n - 1));
}

int	is_arr_sorted_inv(int *arr, int n)
{
	if (n == 1 || n == 0)
		return (1);
	if (arr[n - 1] > arr[n - 2])
		return (0);
	return (is_arr_sorted_inv(arr, n - 1));
} */

void	ft_print_str(char *s)
{
	while (*s)
		write(1, s++, 1);
}
