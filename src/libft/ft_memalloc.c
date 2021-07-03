/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 20:05:31 by mderri            #+#    #+#             */
/*   Updated: 2019/10/01 00:56:48 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t *zf;
	size_t i;

	i = 0;
	zf = (size_t *)malloc(sizeof(zf) * size);
	if (zf == NULL)
		return (NULL);
	while (i <= size)
	{
		zf[i] = 0;
		i++;
	}
	return (zf);
}
