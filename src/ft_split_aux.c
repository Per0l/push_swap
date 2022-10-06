/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 17:59:11 by aperol-h          #+#    #+#             */
/*   Updated: 2021/10/16 17:35:09 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	if (!d && !s)
		return (NULL);
	while (n-- > 0)
		*d++ = *s++;
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*firsts;
	char		*firstd;
	const char	*lasts;
	char		*lastd;

	if (!dest && !src)
		return (NULL);
	if (dest < src)
	{
		firsts = (const char *) src;
		firstd = (char *) dest;
		while (n--)
			*firstd++ = *firsts++;
	}
	else
	{
		lasts = (const char *)src + (n - 1);
		lastd = (char *)dest + (n - 1);
		while (n--)
			*lastd-- = *lasts--;
	}
	return (dest);
}

unsigned int	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;

	if (!dst || !src)
		return (-1);
	srclen = ft_strlen(src);
	if (srclen + 1 < size)
		ft_memcpy(dst, src, srclen + 1);
	else if (size != 0)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (srclen);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	size1;
	size_t	size2;

	if (!s1 || !s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	newstr = (char *)malloc((size1 + size2 + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	ft_memmove(newstr, s1, size1);
	ft_memmove(newstr + size1, s2, size2);
	newstr[size1 + size2] = '\0';
	return (newstr);
}
