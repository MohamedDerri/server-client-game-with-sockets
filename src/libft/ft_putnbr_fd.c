/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <flan@gmail.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 21:30:13 by mderri            #+#    #+#             */
/*   Updated: 2018/10/17 21:30:39 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 0 && n < 10)
	{
		ft_putchar_fd(n + '0', fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else if (n > -10)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd(n * -1 + '0', fd);
	}
	else
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-1 * (n / 10), fd);
		ft_putchar_fd(-1 * (n % 10) + '0', fd);
	}
}
