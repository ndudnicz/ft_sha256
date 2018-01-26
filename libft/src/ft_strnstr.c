/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:12:23 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/19 15:00:29 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "libftasm.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!*s1 || !*s2)
		i = 0;
	if (ft_strlen(s2) == 0)
		return ((char*)s1);
	if (ft_strlen(s2) > n)
		return (NULL);
	while (s1[i] && i < n)
	{
		while (s1[i] && s2[j] && s1[i] == s2[j] && i < n)
		{
			i++;
			j++;
		}
		if (j == ft_strlen(s2))
			return ((char*)&s1[i - j]);
		else
			i = i - j + 1;
		j = 0;
	}
	return (NULL);
}
