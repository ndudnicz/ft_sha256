/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase_uint64.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 09:41:10 by ndudnicz          #+#    #+#             */
/*   Updated: 2017/09/21 09:41:11 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftasm.h"
#include <stdint.h>

void	ft_putbase_uint64(uint64_t nb, unsigned int const base)
{
	if (nb >= base)
	{
		ft_putbase_uint64(nb % base, base);
		ft_putbase_uint64(nb / base, base);
	}
	else
		ft_putchar(nb > 9 ? 97 + (nb - 10) : 48 + nb);
}
