/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:45:57 by aperol-h          #+#    #+#             */
/*   Updated: 2021/10/08 18:53:52 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_chunk **lst)
{
	t_chunk	*tmp;

	if (!lst || !*lst)
		return ;
	while (lst && *lst)
	{
		tmp = (*lst)->next;
		free((*lst)->s_arr);
		free(*lst);
		*lst = tmp;
	}
}

t_chunk	*ft_lstnew(int s, char col)
{
	t_chunk	*new;

	new = ft_pmalloc(sizeof(t_chunk));
	new->size = s;
	new->next = NULL;
	new->s_arr = ft_pmalloc((s + 1) * sizeof(int));
	new->col = col;
	return (new);
}

void	ft_lstadd_front(t_chunks *chunks, t_chunk *new)
{
	if (chunks->list)
		new->next = chunks->list;
	else
		new->next = NULL;
	chunks->list = new;
	chunks->size++;
}

void	ft_lsdelfirst(t_chunks *lst)
{
	t_chunk	*tmp;

	free(lst->list->s_arr);
	tmp = lst->list->next;
	free(lst->list);
	lst->list = tmp;
	lst->size--;
}
