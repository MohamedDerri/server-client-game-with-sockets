/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 00:19:47 by mderri            #+#    #+#             */
/*   Updated: 2018/10/13 00:19:49 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hay;
	char	*nee;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 1;
	hay = (char *)haystack;
	nee = (char *)needle;
	if (!*nee)
		return (hay);
	k = ft_strlen(nee);
	while (hay[i] != '\0' && k <= (int)len - i)
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
