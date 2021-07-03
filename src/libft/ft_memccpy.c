/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 23:55:59 by mderri            #+#    #+#             */
/*   Updated: 2018/10/08 23:56:00 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *memdst;
	unsigned char *memsrc;
	unsigned char ch;

	memsrc = (unsigned char *)src;
	memdst = (unsigned char *)dst;
	ch = (unsigned char)c;
	while (n > 0)
	{
		*(memdst++) = *(memsrc++);
		if (*(memsrc - 1) == ch)
		{
			return (memdst);
		}
		n--;
	}
	return (NULL);
}
