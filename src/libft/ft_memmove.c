/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 22:42:54 by mderri            #+#    #+#             */
/*   Updated: 2018/10/09 22:42:56 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*memdst;
	unsigned char	*memsrc;
	int				i;

	i = (int)len;
	memsrc = (unsigned char *)src;
	memdst = (unsigned char *)dst;
	if (src > dst)
		ft_memcpy(memdst, memsrc, len);
	else
		while (i--)
			memdst[i] = memsrc[i];
	return (dst);
}
