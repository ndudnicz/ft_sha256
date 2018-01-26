/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:49:50 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/19 15:02:44 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "libftasm.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*temp;
	char	*new_dst;
	char	*new_src;
	size_t	i;

	i = 0;
	new_dst = dst;
	new_src = (char*)src;
	if (*new_dst || *new_src)
		i = 0;
	if (len == 0)
		return (NULL);
	if ((temp = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	ft_memcpy(temp, src, len);
	while (i < len)
	{
		new_dst[i] = temp[i];
		i++;
	}
	free(temp);
	return (dst);
}
