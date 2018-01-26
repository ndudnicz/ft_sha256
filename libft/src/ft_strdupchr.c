/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:50:10 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/19 14:53:42 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdupchr(const char *s1, int c)
{
	size_t		i;
	size_t		len_chr;
	char		*str;

	i = 0;
	if (!s1)
		return (NULL);
	len_chr = ft_strlenchr(s1, c);
	if ((str = (char*)malloc(sizeof(char) * len_chr + 1)) == NULL)
		return (NULL);
	while (s1[i] && i < len_chr)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
