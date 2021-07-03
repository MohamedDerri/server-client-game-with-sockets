/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 21:51:19 by mderri            #+#    #+#             */
/*   Updated: 2018/10/11 21:51:22 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int	i;
	int k;

	i = 0;
	k = (int)len;
	while (i < k && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	while (i < k)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
