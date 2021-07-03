/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 22:43:51 by mderri            #+#    #+#             */
/*   Updated: 2018/10/11 22:43:54 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int i;
	int k;
	int l;
	int j;

	l = ft_strlen(src);
	i = ft_strlen(dst);
	k = (int)size;
	j = 0;
	if (k < i)
		l = l + k;
	else
		l = l + i;
	while (src[j] != '\0' && i + 1 < k)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (l);
}
