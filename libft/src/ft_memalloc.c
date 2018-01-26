/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:14:59 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/19 15:05:24 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*memory;

	i = 0;
	if ((memory = (char*)malloc(size)) == NULL)
		return (NULL);
	while (i < size)
	{
		memory[i] = 0;
		i++;
	}
	return (memory);
}
