/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 20:45:39 by mderri            #+#    #+#             */
/*   Updated: 2018/10/12 20:45:42 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t		i;
	char		*str;
	char		*res;

	i = 0;
	res = NULL;
	str = (char *)s;
	while (i <= ft_strlen(s))
	{
		if (*str == (char)c)
			res = str;
		str++;
		i++;
	}
	return (res);
}
