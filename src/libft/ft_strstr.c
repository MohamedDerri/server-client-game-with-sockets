/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 23:06:09 by mderri            #+#    #+#             */
/*   Updated: 2018/10/12 23:06:10 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*hay;
	char	*nee;
	int		i;
	int		j;

	i = 0;
	j = 1;
	hay = (char *)haystack;
	nee = (char *)needle;
	if (nee[0] == '\0')
		return (hay);
	while (hay[i] != '\0')
	{
		if (hay[i] == nee[0])
		{
			while (hay[i + j] == nee[j] && nee[j] != '\0')
				j++;
			if (nee[j] == '\0')
				return (&hay[i]);
		}
		i++;
	}
	return (NULL);
}
