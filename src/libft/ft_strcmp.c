/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 01:11:25 by mderri            #+#    #+#             */
/*   Updated: 2018/10/13 01:11:27 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char *s3;
	const unsigned char *s4;
	int					i;

	i = 0;
	s3 = (const unsigned char *)s1;
	s4 = (const unsigned char *)s2;
	while (s3[i])
	{
		if (s3[i] != s4[i])
			return (s3[i] - s4[i]);
		i++;
	}
	return (s3[i] - s4[i]);
}
