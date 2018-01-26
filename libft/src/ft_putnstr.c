/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 11:05:21 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/13 15:54:56 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "libftasm.h"

int		ft_putnstr(char *str, int n)
{
	int		i;

	i = ft_strlen(str);
	write(1, str, i < n ? i : n);
	return (i);
}
