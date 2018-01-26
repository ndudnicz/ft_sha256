/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:17:10 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/19 15:02:05 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*new_s;
	unsigned char		new_c;

	i = 0;
	new_c = (unsigned char)c;
	new_s = (unsigned char*)s;
	while (i < n)
	{
		if (new_s[i] == new_c)
			return (new_s + i);
		i++;
	}
	return (NULL);
}
