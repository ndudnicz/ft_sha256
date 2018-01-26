/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 07:19:21 by ndudnicz          #+#    #+#             */
/*   Updated: 2015/11/24 07:21:50 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftasm.h"

int		ft_putendl(char const *s)
{
	int const	ret = ft_putstr(s) + 1;

	ft_putchar('\n');
	return (ret);
}
