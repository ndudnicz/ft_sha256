/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:02:59 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/19 15:01:36 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*new_s1;
	char	*new_s2;

	new_s1 = (char*)s1;
	new_s2 = (char*)s2;
	if (n == 0)
		return (0);
	if (n - 1 > 0 && *new_s1 == *new_s2)
		return (ft_memcmp(s1 + 1, s2 + 1, n - 1));
	else
		return ((unsigned char)*new_s1 - (unsigned char)*new_s2);
}
