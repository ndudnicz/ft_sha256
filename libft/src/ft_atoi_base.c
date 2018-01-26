/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 10:23:24 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/22 10:35:46 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftasm.h"

int		ft_atoi_base(char *str, int base)
{
	int		n;

	n = 0;
	if (base > 36 || base < 2 || !str)
		return (0);
	while (ft_strchr(" \t\n\r\v\f", *str))
		str++;
	while (ft_isalnum(*str))
	{
		if (ft_isdigit(*str))
			n = *str - 48 + n * base;
		else if (*str >= 65 && *str <= 90)
			n = *str - 55 + n * base;
		else if (*str >= 97 && *str <= 122)
			n = *str - 87 + n * base;
		str++;
	}
	return (n);
}
