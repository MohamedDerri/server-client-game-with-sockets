/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 16:20:26 by mderri            #+#    #+#             */
/*   Updated: 2018/10/13 16:20:29 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		spacesdmt(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\v'
		|| str[i] == '\t' || str[i] == '\r' || str[i] == '\n')
	{
		i++;
	}
	return (i);
}

int				ft_atoi(const char *str)
{
	int r;
	int s;
	int	i;

	r = 0;
	i = spacesdmt((char *)str);
	s = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			s = -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (int)str[i] - '0';
		i++;
	}
	return (r * s);
}
