/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <flan@gmail.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 20:30:47 by mderri            #+#    #+#             */
/*   Updated: 2018/10/17 20:30:50 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n >= 0 && n < 10)
	{
		ft_putchar(n + '0');
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else if (n > -10)
	{
		ft_putchar('-');
		ft_putchar(n * -1 + '0');
	}
	else
	{
		ft_putchar('-');
		ft_putnbr(-1 * (n / 10));
		ft_putchar(-1 * (n % 10) + '0');
	}
}
