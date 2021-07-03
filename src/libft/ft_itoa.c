/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 22:43:10 by mderri            #+#    #+#             */
/*   Updated: 2019/10/01 00:50:08 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_bytes_nb(int n)
{
	int		i;
	long	nb;

	i = 0;
	nb = (long)n;
	if (nb < 0)
	{
		i++;
		nb = nb * -1;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		nb_bt;
	long	nb;

	nb_bt = ft_count_bytes_nb(n);
	str = (char *)ft_memalloc(sizeof(char) * (nb_bt + 1));
	if (!str)
		return (NULL);
	nb = (long)n;
	if (n < 0)
		nb = nb * -1;
	str[nb_bt] = '\0';
	nb_bt--;
	while (nb >= 0)
	{
		str[nb_bt] = (nb % 10) + '0';
		nb = nb / 10;
		nb_bt--;
		if (nb_bt == -1)
			break ;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
