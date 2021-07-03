/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 23:40:36 by mderri            #+#    #+#             */
/*   Updated: 2018/10/13 23:40:38 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	i;

	if (!s1 || !s2)
		return (0);
	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	while (i <= ft_strlen(str1) && i < n)
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}
