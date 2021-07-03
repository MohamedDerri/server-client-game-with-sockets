/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 23:14:53 by mderri            #+#    #+#             */
/*   Updated: 2019/10/01 00:57:17 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*zf;
	char	*aux;
	size_t	i;

	i = 0;
	aux = (char *)s;
	if (aux == NULL)
		return (NULL);
	zf = (char *)malloc(sizeof(char) * (ft_strlen(aux) + 1));
	if (zf == NULL)
		return (NULL);
	while (i < ft_strlen(aux))
	{
		zf[i] = (*f)(i, aux[i]);
		i++;
	}
	zf[i] = '\0';
	return (zf);
}
