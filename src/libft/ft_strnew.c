/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 21:42:42 by mderri            #+#    #+#             */
/*   Updated: 2019/10/01 00:57:22 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*zf;
	size_t	i;

	i = 0;
	zf = (char *)malloc(sizeof(char) * (size + 1));
	if (zf == NULL)
		return (NULL);
	while (i <= size)
	{
		zf[i] = '\0';
		i++;
	}
	zf[i] = '\0';
	return (zf);
}
