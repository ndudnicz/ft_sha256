/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 07:35:51 by ndudnicz          #+#    #+#             */
/*   Updated: 2015/11/26 21:03:15 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftasm.h"

static void			ft_u_putnbr_fd(unsigned int n, int fd)
{
	if (n >= 10)
	{
		ft_u_putnbr_fd(n / 10, fd);
		ft_u_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
}

void				ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_u_putnbr_fd(-n, fd);
	}
	else
		ft_u_putnbr_fd(n, fd);
}
