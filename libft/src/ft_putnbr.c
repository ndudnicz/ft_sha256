/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 07:22:05 by ndudnicz          #+#    #+#             */
/*   Updated: 2015/11/26 21:02:49 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftasm.h"

static void		ft_u_putnbr(unsigned int n)
{
	if (n >= 10)
	{
		ft_u_putnbr(n / 10);
		ft_u_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

void			ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_u_putnbr(-n);
	}
	else
		ft_u_putnbr(n);
}
