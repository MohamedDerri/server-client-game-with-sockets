/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 23:21:37 by mderri            #+#    #+#             */
/*   Updated: 2018/10/09 23:21:40 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *dst;

	dst = (unsigned char *)s;
	while (n--)
	{
		if (*dst == (unsigned char)c)
			return (dst);
		dst++;
	}
	return (NULL);
}
