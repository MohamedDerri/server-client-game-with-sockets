/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 23:04:28 by mderri            #+#    #+#             */
/*   Updated: 2018/10/08 23:04:30 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *memdst;
	unsigned char *memsrc;

	memsrc = (unsigned char *)src;
	memdst = (unsigned char *)dst;
	while (n--)
	{
		*(memdst++) = *(memsrc++);
	}
	return (dst);
}
