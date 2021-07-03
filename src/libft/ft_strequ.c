/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 23:21:15 by mderri            #+#    #+#             */
/*   Updated: 2019/09/30 00:32:15 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	const char	*s3;
	const char	*s4;
	int			i;
	int			len;

	i = 0;
	s3 = (const char *)s1;
	s4 = (const char *)s2;
	len = (int)ft_strlen(s3);
	if (!s3 || !s4)
		return (0);
	while (i <= len)
	{
		if (s3[i] != s4[i])
			return (0);
		i++;
	}
	return (1);
}
