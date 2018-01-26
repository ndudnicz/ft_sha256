/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 17:14:31 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/20 09:23:43 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftasm.h"

void	ft_putbase(long int value, char base, char upper)
{
	(value < 0 && base == 10) ? ft_putchar('-') : 1;
	value = value < 0 ? -value : value;
	if (base <= 36 && base >= 2)
	{
		if (value >= base)
		{
			ft_putbase(value / base, base, upper);
			ft_putbase(value % base, base, upper);
		}
		else
		{
			if (value > 9)
				upper != 0 ? ft_putchar(value + 55) : ft_putchar(value + 87);
			else
				ft_putchar(value + 48);
		}
	}
	else
		ft_putchar('0');
}
