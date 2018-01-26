/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:50:10 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/19 15:11:06 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftasm.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*str;

	len = ft_strlen(s1) + 1;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	ft_memcpy(str, s1, len);
	return (str);
}
